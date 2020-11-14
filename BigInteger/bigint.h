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
	std::vector <long long> value;

public:

	static const long long mod;
	static const int cellSize;
	static const BigInteger ZERO;
	static const BigInteger ONE;
	static const BigInteger TEN;

	BigInteger();

	BigInteger(const short &setSign, const std::vector <long long> &setValue);

	BigInteger operator+(const BigInteger second) const;

	BigInteger operator+=(const BigInteger second);

	BigInteger operator-(const BigInteger second) const;

	BigInteger operator-=(const BigInteger second);

	BigInteger operator-() const;

	BigInteger operator--();

	BigInteger operator++();

	BigInteger operator--(int);

	BigInteger operator++(int);

	BigInteger operator*(const BigInteger second) const;

	BigInteger operator*=(const BigInteger second);

	BigInteger operator/(const BigInteger second) const;

	BigInteger operator/=(const BigInteger second);

	BigInteger operator%(const BigInteger second) const;

	BigInteger operator%=(const BigInteger second);

	bool operator>(const BigInteger second) const;

	bool operator>=(const BigInteger second) const;

	bool operator<(const BigInteger second) const;

	bool operator<=(const BigInteger second) const;

	bool operator==(const BigInteger second) const;

	friend std::ostream &operator<<(std::ostream &out, const BigInteger num);

	static BigInteger valueOf(const long long num);

	static BigInteger valueOf(const std::string str);

	static BigInteger pow(BigInteger value, long long ext);

	std::string toString() const;

	int toInt() const;

	long long toLong() const;

	BigInteger abs() const;
};