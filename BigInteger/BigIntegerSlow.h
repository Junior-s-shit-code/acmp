#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

class BigInteger {
	short sign = 1;
	std::vector <short int> value;

public:

	BigInteger()
		: sign(1)
		, value(0)
	{}

	BigInteger operator +(BigInteger second) {
		BigInteger newNum;
		if (sign == second.sign) {
			newNum.sign = sign;
			newNum.value = value;
			
			for (int i = 0; i < (int)second.value.size(); i++) {
				if (i == newNum.value.size()) {
					newNum.value.push_back(0);
				}
				newNum.value[i] += second.value[i];
				int extra = newNum.value[i] / 10;
				newNum.value[i] %= 10;
				if (extra > 0 && i + 1 == (int)second.value.size()) {
					newNum.value.push_back(extra);
				}
			}
			return newNum;

		} else if (sign == -1) {
			return second - *this;
		} else {
			return *this - second;
		}
	}

	BigInteger operator -(BigInteger second) {
		if (sign == 1 && second.sign == -1) {
			return *this + -second;
		} else if (sign == -1 && second.sign == 1) {
			return *this + -second;
		} else if (sign == -1) {
			return (-second) - (-*this);
		} else {
			if (*this >= second) {
				BigInteger newNum = *this;
				for (int i = 0; i < (int)second.value.size(); i++) {
					newNum.value[i] -= second.value[i];
					if (newNum.value[i] < 0) {
						newNum.value[i] += 10;
						newNum.value[i + 1]--;
					}
				}
				return newNum;
			} else {
				return -(second - *this);
			}
		}
	}

	BigInteger operator -() const{
		BigInteger newNum = *this;
		newNum.sign *= -1;
		return newNum;
	}

	BigInteger operator *(const BigInteger second) {
		BigInteger newNum;
		newNum.sign = sign * second.sign;
		for (int i = 0; i < (int)value.size(); i++) {
			for (int j = 0; j < (int)second.value.size(); j++) {
				if (i + j == (int) newNum.value.size()) {
					newNum.value.push_back(0);
				}
				newNum.value[i + j] += value[i] * second.value[j];
				int extra = newNum.value[i + j] / 10;
				if (extra > 0 && i + j + 1 == (int)newNum.value.size()) {
					newNum.value.push_back(extra);
				} else if (extra > 0) {
					newNum.value[i + j + 1] += extra; //  need to prove that the value in the highest digit will not exceed 9, or that we will consider it
				}
			}
		}
		return newNum;
	}

	BigInteger operator /(const BigInteger second) {

	}

	BigInteger operator =(long long second) {
		if (second < 0) {
			sign = -1;
			second *= -1;
		}
		while (second != 0) {
			value.push_back(second % 10);
			second /= 10;
		}
		return *this;
	}

	BigInteger operator =(const std::string &second) {
		*this = valueOf(second);
		return *this;
	}

	bool operator >(const BigInteger second) const {
		std::string str1 = "";
		for (int i = (int)value.size() - 1; i >= 0; i--) {
			str1 += (value[i] + '0');
		}
		std::string str2 = "";
		for (int i = (int)second.value.size() - 1; i >= 0; i--) {
			str2 += (second.value[i] + '0');
		}
		int size1 = str1.length();
		int size2 = str2.length();


		if (sign == 1 && second.sign == -1) {
			return true;
		} else if (sign == -1 && second.sign == 1) {
			return false;
		} else if (sign == 1) {  // wanna be optimized with bit-arithmetic
			if ((size1 > size2) || (size1 == size2 && str1 > str2)) {
				return true;
			} else {
				return false;
			}
		} else {
			if ((size1 > size2) || (size1 == size2 && str1 > str2)) {
				return false;
			} else {
				return true;
			}
		}
	}

	bool operator >=(const BigInteger second) const {
		if (*this > second || *this == second) {
			return true;
		} 
		return false;
	}

	bool operator <(const BigInteger second) const {
		if (!(*this >= second)) {
			return true;
		}
		return false;
	}

	bool operator <= (const BigInteger second) const {
		if (!(*this > second)) {
			return true;
		}
		return false;
	}

	bool operator ==(const BigInteger second) const { //to correct work wanna delete useless cells in value, while we do operator ( - )
		if (*this == second) {
			return true;
		}
		return false;
	}

	static BigInteger valueOf(long long num) {
		return valueOf(std::to_string(num).c_str());
	}

	static BigInteger valueOf(std::string str) {
		BigInteger newNum;
		int end = 0;
		if (str[0] == '-') {
			newNum.sign = -1;
			end++;
		}
		for (int i = (int)str.length() - 1; i >= end; i--) {
			newNum.value.push_back((short int) (str[i] - '0'));
		}
		return newNum;
	}

	std::string toString() const {
		std::string ans = "";
		if (sign == -1) {
			ans += '-';
		}
		for (int i = (int)value.size() - 1; i >= 0; i--) {
			ans += (value[i] + '0');
		}
		return ans;
	}
};