#include <stdio.h>
#include <vector>
#include <algorithm>

const int NOT_GOOD = -1;
const int UNKNOWN = 0;
const int GOOD = 1;

int sumDigitsSquare(long long num) {
	int ans = 0;
	while (num > 0) {
		int d = num % 10;
		ans += d * d;
		num /= 10;
	}
	return ans;
}

bool isWanted(int num, std::vector<int> &numberType) {
	if (numberType[num] == UNKNOWN) {
		numberType[num] = NOT_GOOD;
		if (isWanted(sumDigitsSquare(num), numberType)) {
			numberType[num] = GOOD;
		}
	}
	return numberType[num] == GOOD;
}

long long countGoodTill(long long value,
						const int maxSum,
						std::vector<int> &numberType,
						const std::vector<std::vector<long long>> &countGood) {
	std::vector<long long> sum(maxSum + 1, 0);
	sum[sumDigitsSquare(value)] = 1;

	for (int digits = 0; value > 0; digits++) {
		int curDigitValue = value % 10;
		value /= 10;
		int curSum = sumDigitsSquare(value);
		for (int d = 0; d < curDigitValue; d++) {
			int digitSquare = d * d;
			for (int i = 0; i <= maxSum - curSum - digitSquare; i++) {
				sum[i + curSum + digitSquare] = sum[i + curSum + digitSquare] + countGood[digits][i];
			}
		}
	}

	long long ans = 0;
	for (int value = 0; value <= maxSum; value++) {
		if (isWanted(value, numberType)) {
			ans += sum[value];
		}
	}
	return ans;
}

void preCalculations(const int maxSum,
					 const int maxDigits,
					 std::vector<int> &numberType,
					 std::vector<std::vector<long long>> &countGood) {
	numberType[0] = NOT_GOOD;
	numberType[1] = GOOD;
	for (int value = 0; value <= maxSum; value++) {
		isWanted(value, numberType);
	}
	countGood[0][0] = 1;
	for (int len = 1; len <= maxDigits; len++) {
		for (int d = 0; d < 10; d++) {
			int digitSquare = d * d;
			for (int i = 0; i <= maxSum - digitSquare; i++) {
				countGood[len][i + digitSquare] = countGood[len][i + digitSquare] + countGood[len - 1][i];
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int MAX_DIGITS = 18;
	const int MAX_SUM = MAX_DIGITS * 81;
	std::vector<int> numberType(MAX_SUM + 1, UNKNOWN);
	std::vector<std::vector<long long>> countGood(MAX_DIGITS + 1, std::vector<long long>(MAX_SUM + 1, 0));
	preCalculations(MAX_SUM, MAX_DIGITS, numberType, countGood);
	long long left, right;
	scanf("%lld %lld", &left, &right);
	printf("%lld", 
		   countGoodTill(right, MAX_SUM, numberType, countGood) - 
		   countGoodTill(left - 1, MAX_SUM, numberType, countGood)
	);
	return 0;
}