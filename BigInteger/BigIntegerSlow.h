#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cassert>

class BigInteger {

private:

	short sign = 1;
	std::vector <short> value;

public:

	BigInteger()
		: sign(1)
		, value(0) {}

	BigInteger(const short &setSign, const std::vector <short> &setValue)
		: sign(setSign)
		, value(setValue) {}

	BigInteger operator + (BigInteger second) {
		if (sign == second.sign && sign == 1) {
			BigInteger newValue;
			int n1 = (int)value.size();
			int n2 = (int)second.value.size();
			for (int i = 0; i < (int)std::max(n1, n2); i++) {
				int curSum = 0;
				if (i < n1) {
					curSum += value[i];
				}
				if (i < n2) {
					curSum += second.value[i];
				}
				int extra = curSum / 10;
				curSum %= 10;
				if (i >= (int)newValue.value.size()) {
					newValue.value.push_back(curSum);
				} else {
					newValue.value[i] += curSum;
					extra += newValue.value[i] / 10;
					newValue.value[i] %= 10;
				}

				if (extra > 0 && i + 1 >= (int)newValue.value.size()) {
					newValue.value.push_back(extra);
				} else if (extra > 0) {
					newValue.value[i + 1] += extra;
				}
			}
			return newValue;
		} else if (sign == second.sign) {
			return -(this->abs() + second.abs());
		} else if (sign == -1) {
			return second - this->abs();
		} else {
			return *this - second.abs();
		}
	}

	BigInteger operator += (const BigInteger second) {
		*this = *this + second;
		return *this;
	}

	BigInteger operator -(BigInteger second) {
		if (sign == second.sign && sign == -1) {
			return (second.abs() - (this->abs()));
		} else if (sign == second.sign) {
			if (*this == second) {
				return BigInteger::valueOf(0);
			} else if (*this < second) {
				return -(second - *this);
			} else {
				BigInteger newValue = *this;
				assert(newValue.sign == 1);
				for (int i = 0; i < (int)newValue.value.size(); i++) {
					if (i < (int)second.value.size()) {
						newValue.value[i] -= second.value[i];
					}
					if (newValue.value[i] < 0) {
						newValue.value[i] += 10;
						assert(i + 1 < (int)newValue.value.size());
						newValue.value[i + 1]--;
					}
				}

				int end = (int)newValue.value.size() - 1;
				while (newValue.value[end] == 0) {
					end--;
				}
				std::vector <short> ans(end + 1);
				for (int i = 0; i <= end; i++) {
					ans[i] = newValue.value[i];
				}
				return BigInteger { 1, ans };
			}
		} else if (sign == -1) {
			return -(this->abs() + second);
		} else {
			return *this + second.abs();
		}
	}

	BigInteger operator -= (const BigInteger second) {
		*this = *this - second;
		return *this;
	}

	BigInteger operator -() const {
		return BigInteger { sign * -1, value };
	}

	BigInteger operator --() {
		*this = *this - BigInteger::valueOf(1);
		return *this;
	}

	BigInteger operator ++() {
		*this = *this + BigInteger::valueOf(1);
		return *this;
	}

	BigInteger operator --(int) {
		return -- * this;
	}

	BigInteger operator ++(int) {
		return ++ * this;
	}

	BigInteger operator *(const BigInteger second) {
		const BigInteger null = BigInteger::valueOf(0);
		if (*this == null || second == null) {
			return null;
		}
		BigInteger newNum;
		newNum.sign = sign * second.sign;
		for (int i = 0; i < (int)value.size(); i++) {
			for (int j = 0; j < (int)second.value.size(); j++) {
				if (i + j == (int)newNum.value.size()) {
					newNum.value.push_back(0);
				}
				newNum.value[i + j] += value[i] * second.value[j];
				int extra = newNum.value[i + j] / 10;
				newNum.value[i + j] %= 10;
				if (extra > 0 && i + j + 1 == (int)newNum.value.size()) {
					newNum.value.push_back(extra);
				} else if (extra > 0) {
					newNum.value[i + j + 1] += extra; //  need to prove that the value in the highest digit will not exceed 9, or that we will consider it
				}
			}
		}
		return newNum;
	}

	BigInteger operator *= (const BigInteger second) {
		*this = *this * second;
		return *this;
	}

	BigInteger operator /(BigInteger second) { //write second option, when we use '/' like in school and check time
		short newSign = sign * second.sign;
		short selfThisSign = sign;
		sign = second.sign = 1;

		if (*this < second || *this == BigInteger::valueOf(0)) {
			sign = selfThisSign;
			return BigInteger::valueOf(0);
		} else if (*this == second) {
			sign = selfThisSign;
			return BigInteger::valueOf(1);
		}

		std::string item = this->toString();
		std::string divisor = second.toString();
		int start = (int)divisor.length();
		std::string dividend = item.substr(0, start);
		if (dividend >= divisor) {
			start--;
			dividend = item.substr(0, start);
		}

		std::string ans = "";
		const BigInteger b = BigInteger::valueOf(divisor);
		for (int i = start; i < (int)item.length(); i++) {
			dividend += item[i];

			BigInteger a = BigInteger::valueOf(dividend);
			BigInteger curValue = BigInteger::valueOf(0);
			BigInteger nextValue = curValue + b;
			int curAns = 0;
			while (nextValue <= a) {
				curValue = nextValue;
				nextValue += b;
				curAns++;
			}
			a -= curValue;
			dividend = a.toString();
			ans += std::to_string(curAns);
		}

		sign = selfThisSign;

		BigInteger newValue = BigInteger::valueOf(ans);
		newValue.sign = newSign;
		return newValue;
	}

	BigInteger operator /= (const BigInteger second) {
		*this = *this / second;
		return *this;
	}

	BigInteger operator %(const BigInteger second) {
		return *this - ((*this / second) * second);
	}

	BigInteger operator %= (const BigInteger second) {
		*this = *this % second;
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

		if (sign != second.sign) {
			return sign == 1;
		} else {
			return (sign == 1) == ((size1 > size2) || (size1 == size2 && str1 > str2));
		}
	}

	bool operator >=(const BigInteger second) const {
		return (*this > second || *this == second);
	}

	bool operator <(const BigInteger second) const {
		return !(*this >= second);
	}

	bool operator <= (const BigInteger second) const {
		return !(*this > second);
	}

	bool operator ==(const BigInteger second) const { //to correct work wanna delete useless cells in value, while we do operator ( - )  |||   UPD: done
		return (sign == second.sign && value == second.value);
	}

	friend std::ostream &operator << (std::ostream &out, const BigInteger num) {
		std::string ans = num.toString();
		out << ans;
		return out;
	}

	static BigInteger valueOf(long long num) {
		return valueOf(std::to_string(num));
	}

	static BigInteger valueOf(std::string str) {
		BigInteger newNum;
		int end = 0;
		if (str[0] == '-') {
			newNum.sign = -1;
			end++;
		}
		for (int i = (int)str.length() - 1; i >= end; i--) {
			newNum.value.push_back((short)(str[i] - '0'));
		}
		return newNum;
	}

	BigInteger pow(BigInteger value, long long ext) {
		BigInteger ans = BigInteger::valueOf(1);
		while (ext) {
			if (ext & 1) {
				ans *= value;
			}
			value *= value;
			ext >>= 1;
		}
		return ans;
	}

	BigInteger pow(BigInteger value, BigInteger ext) {
		if (value < BigInteger::valueOf(0) || ext < BigInteger::valueOf(0)) {
			throw 1;
		}
		return pow(value, ext.toLong());
	}

	std::string toString() const {
		std::string ans = "";
		for (int i = 0; i < (int)this->value.size(); i++) {
			ans.insert(ans.begin(), this->value[i] + '0');
		}
		if (this->sign == -1) {
			ans = "-" + ans;
		}
		return ans;
	}

	int toInt() const {
		return std::atoi(toString().c_str());
	}

	long long toLong() const {
		return std::atoll(toString().c_str());
	}

	BigInteger abs() const {
		return BigInteger { 1, value };
	}
};