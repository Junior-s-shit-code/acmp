#include <stdio.h>
#include <vector>
#include <algorithm>

int sumDigits(long long num) {
	int ans = 0;
	while (num > 0) {
		int d = num % 10;
		ans += d * d;
		num /= 10;
	}
	return ans;
}

bool isWanted(int num, std::vector<bool> &is, std::vector<bool> &was) {
	if (!was[num]) {
		was[num] = true;
		is[num] = false;
		if (isWanted(sumDigits(num), is, was)) {
			is[num] = true;
		}
	}
	return is[num];
}

long long countWanted(long long value, const int maxSum, std::vector<bool> &is, std::vector<bool> &was, const std::vector<std::vector<long long>> &dp) {
	std::vector<long long> sum(maxSum + 1, 0);
	sum[sumDigits(value)] = 1;

	for (int digits = 0; value > 0; digits++) {
		int curDigitValue = value % 10;
		value /= 10;
		int curSum = sumDigits(value);
		for (int d = 0; d < curDigitValue; d++) {
			int digitSquare = d * d;
			for (int i = 0; i <= maxSum - curSum - digitSquare; i++) {
				sum[i + curSum + digitSquare] = sum[i + curSum + digitSquare] + dp[digits][i];
			}
		}
	}

	long long ans = 0;
	for (int value = 0; value <= maxSum; value++) {
		if (isWanted(value, is, was)) {
			ans += sum[value];
		}
	}
	return ans;
}

void preCalculations(const int maxSum, const int maxDigits, std::vector<bool> &is, std::vector<bool> &was, std::vector<std::vector<long long>> &dp) {
	was[0] = was[1] = true;
	is[1] = true;
	for (int value = 0; value <= maxSum; value++) {
		isWanted(value, is, was);
	}
	dp[0][0] = 1;
	for (int digits = 1; digits <= maxDigits; digits++) {
		for (int d = 0; d < 10; d++) {
			int digitSquare = d * d;
			for (int i = 0; i <= maxSum - digitSquare; i++) {
				dp[digits][i + digitSquare] = dp[digits][i + digitSquare] + dp[digits - 1][i];
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int maxDigits = 18;
	const int maxSum = maxDigits * 81;
	std::vector<bool> is(maxSum + 1, false);
	std::vector<bool> was(maxSum + 1, false);
	std::vector<std::vector<long long>> dp(maxDigits + 1, std::vector<long long>(maxSum + 1, 0));
	preCalculations(maxSum, maxDigits, is, was, dp);
	long long left, right;
	scanf("%lld %lld", &left, &right);
	printf("%lld", countWanted(right, maxSum, is, was, dp) - countWanted(left - 1, maxSum, is, was, dp));
	return 0;
}