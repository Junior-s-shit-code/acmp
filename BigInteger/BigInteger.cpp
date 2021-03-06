#include "bigint.h"

const long long BigInteger::mod = 1000000000;
const int BigInteger::cellSize = 9;
const BigInteger BigInteger::ZERO = BigInteger::valueOf("0");
const BigInteger BigInteger::ONE = BigInteger::valueOf("1");
const BigInteger BigInteger::TEN = BigInteger::valueOf("10");

BigInteger::BigInteger()
	: sign(1)
	, value(0) {}

BigInteger::BigInteger(const short &setSign, const std::vector <long long> &setValue)
	: sign(setSign)
	, value(setValue) {}

BigInteger BigInteger::operator+(const BigInteger second) const{
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
			long long extra = curSum / mod;
			curSum %= mod;
			if (i >= (int)newValue.value.size()) {
				newValue.value.push_back(curSum);
			} else {
				newValue.value[i] += curSum;
				extra += newValue.value[i] / mod;
				newValue.value[i] %= mod;
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
		return sec - this->abs();
	} else {
		return *this - second.abs();
	}
}

BigInteger BigInteger::operator+=(const BigInteger second) {
	*this = *this + second;
	return *this;
}

BigInteger BigInteger::operator-(const BigInteger second) const {
	BigInteger sec = second;
	if (sign == second.sign && sign == -1) {
		return (second.abs() - (this->abs()));
	} else if (sign == second.sign) {
		if (*this == second) {
			return ZERO;
		} else if (*this < second) {
			return -(sec - *this);
		} else {
			BigInteger newValue = *this;
			for (int i = 0; i < (int)newValue.value.size(); i++) {
				if (i < (int)second.value.size()) {
					newValue.value[i] -= second.value[i];
				}
				if (newValue.value[i] < 0) {
					newValue.value[i] += mod;
					newValue.value[i + 1]--;
				}
			}

			int end = (int)newValue.value.size() - 1;
			while (newValue.value[end] == 0) {
				end--;
			}
			std::vector <long long> ans(end + 1);
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

BigInteger BigInteger::operator-=(const BigInteger second) {
	*this = *this - second;
	return *this;
}

BigInteger BigInteger::operator-() const {
	return BigInteger { sign * -1, value };
}

BigInteger BigInteger::operator--() {
	*this = *this - ONE;
	return *this;
}

BigInteger BigInteger::operator++() {
	*this = *this + ONE;
	return *this;
}

BigInteger BigInteger::operator--(int) {
	return -- * this;
}

BigInteger BigInteger::operator++(int) {
	return ++ * this;
}

BigInteger BigInteger::operator*(const BigInteger second) const {
	if (*this == ZERO || second == ZERO) {
		return ZERO;
	}
	BigInteger newNum;
	newNum.sign = sign * second.sign;
	for (int i = 0; i < (int)value.size(); i++) {
		for (int j = 0; j < (int)second.value.size(); j++) {
			if (i + j == (int)newNum.value.size()) {
				newNum.value.push_back(0);
			}
			newNum.value[i + j] += value[i] * second.value[j];
			long long extra = newNum.value[i + j] / mod;
			newNum.value[i + j] %= mod;
			if (extra > 0 && i + j + 1 == (int)newNum.value.size()) {
				newNum.value.push_back(extra);
			} else if (extra > 0) {
				newNum.value[i + j + 1] += extra;
			}
		}
	}
	return newNum;
}

BigInteger BigInteger::operator*=(const BigInteger second) {
	*this = *this * second;
	return *this;
}

BigInteger BigInteger::operator/(const BigInteger second) const {
	short newSign = sign * second.sign;

	if (second.abs() == ZERO) {
		printf("\nError! divisor is null\n");
		return ZERO;
	} else if (second.abs() == ONE) {
		return *this;
	} else if (this->abs() < second.abs()) {
		return ZERO;
	}

	std::string thisStr = this->abs().toString();
	BigInteger curDividend;
	std::string curDividendStr = "";
	std::string secondStr = second.abs().toString();
	int secLen = (int)secondStr.length();
	int start = 0;
	int thisSize = (int)thisStr.length();

	for (start = 0; start < thisSize; start++) {
		curDividendStr += thisStr[start];
		int curDivLen = (int)curDividendStr.length();
		if ((int)curDivLen > (int)secLen || (curDivLen == secLen && curDivLen >= secLen)) {
			break;
		}
	}
	curDividend = valueOf(curDividendStr);
	std::string ans = "";
	while (start < thisSize) {
		BigInteger curDivisor = ZERO;
		BigInteger nextDivisor = second.abs();
		int curAns = 0;
		while (nextDivisor <= curDividend) {
			curDivisor = nextDivisor;
			nextDivisor += second.abs();
			curAns++;
		}

		ans += std::to_string(curAns);
		start++;
		if (start < thisSize) {
			curDividend -= curDivisor;
			curDividendStr = curDividend.toString();
			char c = thisStr[start];
			if (!(curDividendStr == "0" && c == '0')) {
				curDividendStr += thisStr[start];
			}
			curDividend = valueOf(curDividendStr);
		}

	}
	while ((int)ans.length() > 1 && ans[0] == '0') {
		ans.erase(ans.begin());
	}
	BigInteger newValue = valueOf(ans);
	newValue.sign = newSign;
	return newValue;
}

BigInteger BigInteger::operator/=(const BigInteger second) {
	*this = *this / second;
	return *this;
}

BigInteger BigInteger::operator%(const BigInteger second) const{
	return *this - ((*this / second) * second);
}

BigInteger BigInteger::operator%=(const BigInteger second) {
	*this = *this % second;
	return *this;
}

bool BigInteger::operator>(const BigInteger second) const {
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

bool BigInteger::operator>=(const BigInteger second) const {
	return (*this > second || *this == second);
}

bool BigInteger::operator<(const BigInteger second) const {
	return !(*this >= second);
}

bool BigInteger::operator<=(const BigInteger second) const {
	return !(*this > second);
}

bool BigInteger::operator==(const BigInteger second) const {
	return (sign == second.sign && value == second.value);
}

std::ostream &operator<<(std::ostream &out, const BigInteger num) {
	std::string ans = num.toString();
	out << ans;
	return out;
}

BigInteger BigInteger::valueOf(const long long num) {
	return valueOf(std::to_string(num));
}

BigInteger BigInteger::valueOf(const std::string str) {
	BigInteger newNum;
	for (int i = (int)str.length() - 1; i >= 0; i -= cellSize) {
		std::string newCell = "";

		for (int j = (i - cellSize + 1 < 0 ? i : cellSize - 1); j >= 0; j--) {
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

BigInteger BigInteger::pow(BigInteger value, long long ext) {
	if (ext < 0) {
		throw 1;
	}
	BigInteger ans = ONE;
	while (ext) {
		if (ext & 1) {
			ans *= value;
		}
		value *= value;
		ext >>= 1;
	}
	return ans;
}

std::string BigInteger::toString() const {
	std::string ans = "";
	for (int i = 0; i < (int)value.size(); i++) {
		std::string newStr = std::to_string(value[i]);
		if (i < (int)value.size() - 1) {
			while ((int)newStr.length() < cellSize) {
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

int BigInteger::toInt() const {
	return std::atoi(toString().c_str());
}

long long BigInteger::toLong() const {
	return std::atoll(toString().c_str());
}

BigInteger BigInteger::abs() const {
	return BigInteger { 1, value };
}
