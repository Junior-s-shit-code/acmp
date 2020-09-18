#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

class BigInteger {

private:

	short sign = 1;
	std::vector <long long> value;

public:

	static const long long MOD = 1000000000;
	static const int CELL_SIZE = 9;

	BigInteger()
		: sign(1)
		, value(0) {}

	BigInteger(const short &setSign, const std::vector <long long> &setValue)
		: sign(setSign)
		, value(setValue) {}

	static BigInteger ZERO() {
		return valueOf("0");
	}

	static BigInteger ONE() {
		return valueOf("1");
	}

	static BigInteger TEN() {
		return valueOf("10");
	}

	BigInteger operator+(const BigInteger second) const {
		BigInteger sec = second;
		if (sign == second.sign && sign == 1) {
			BigInteger newValue;
			int n1 = (int)value.size();
			int n2 = (int)second.value.size();
			for (int i = 0; i < (int)std::max(n1, n2); i++) {
				long long curSum = 0;
				if (i < n1) {
					curSum += value[i];
				}
				if (i < n2) {
					curSum += second.value[i];
				}
				long long extra = curSum / MOD;
				curSum %= MOD;
				if (i >= (int)newValue.value.size()) {
					newValue.value.push_back(curSum);
				} else {
					newValue.value[i] += curSum;
					extra += newValue.value[i] / MOD;
					newValue.value[i] %= MOD;
				}

				if (extra > 0 && i + 1 >= (int)newValue.value.size()) {
					newValue.value.push_back(extra);
				} else if (extra > 0) {
					newValue.value[i + 1] += extra;
				}
			}
			return newValue;
		} else {
			throw 1;
		}
	}

	BigInteger operator+=(const BigInteger second) {
		*this = *this + second;
		return *this;
	}


	BigInteger operator-() const {
		return BigInteger{ sign * -1, value };
	}

	BigInteger operator*(const BigInteger second) const {
		if (*this == ZERO() || second == ZERO()) {
			return ZERO();
		}
		BigInteger newNum;
		newNum.sign = sign * second.sign;
		for (int i = 0; i < (int)value.size(); i++) {
			for (int j = 0; j < (int)second.value.size(); j++) {
				if (i + j == (int)newNum.value.size()) {
					newNum.value.push_back(0);
				}
				newNum.value[i + j] += value[i] * second.value[j];
				long long extra = newNum.value[i + j] / MOD;
				newNum.value[i + j] %= MOD;
				if (extra > 0 && i + j + 1 == (int)newNum.value.size()) {
					newNum.value.push_back(extra);
				} else if (extra > 0) {
					newNum.value[i + j + 1] += extra;
				}
			}
		}
		return newNum;
	}

	BigInteger operator*=(const BigInteger second) {
		*this = *this * second;
		return *this;
	}

	bool operator>(const BigInteger second) const {
		std::string str1 = this->toString();
		std::string str2 = second.toString();
		int size1 = str1.length();
		int size2 = str2.length();

		if (sign != second.sign) {
			return sign == 1;
		} else {
			return (sign == 1) == ((size1 > size2) || (size1 == size2 && str1 > str2));
		}
	}

	bool operator>=(const BigInteger second) const {
		return (*this > second || *this == second);
	}

	bool operator<(const BigInteger second) const {
		return !(*this >= second);
	}

	bool operator<=(const BigInteger second) const {
		return !(*this > second);
	}

	bool operator==(const BigInteger second) const {
		return (sign == second.sign && value == second.value);
	}


	static BigInteger valueOf(const std::string str) {
		BigInteger newNum;
		for (int i = (int)str.length() - 1; i >= 0; i -= CELL_SIZE) {
			std::string newCell = "";

			for (int j = (i - CELL_SIZE + 1 < 0 ? i : CELL_SIZE - 1); j >= 0; j--) {
				newCell += str[i - j];
			}
			if (newCell == "-") {
				newNum.sign = -1;
				break;
			}
			newNum.value.push_back(std::atoll(newCell.c_str()));
		}
		int last = (int)newNum.value.size() - 1;
		if (newNum.value[last] < 0) {
			newNum.value[last] *= -1;
			newNum.sign = -1;
		}
		return newNum;
	}

	static BigInteger pow(BigInteger value, long long ext) {
		if (ext < 0) {
			throw 1;
		}
		BigInteger ans = valueOf("1");
		while (ext) {
			if (ext & 1) {
				ans *= value;
			}
			value *= value;
			ext >>= 1;
		}
		return ans;
	}

	std::string toString() const {
		std::string ans = "";
		for (int i = 0; i < (int)value.size(); i++) {
			std::string newStr = std::to_string(value[i]);
			if (i < (int)value.size() - 1) {
				while ((int)newStr.length() < CELL_SIZE) {
					newStr.insert(newStr.begin(), '0');
				}
			}
			ans = newStr + ans;
		}
		if (sign == -1) {
			ans = "-" + ans;
		}
		return ans;
	}


};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	BigInteger ans = BigInteger::pow(BigInteger::valueOf("45"), n);
	printf("%s", ans.toString().c_str());
    return 0;
}