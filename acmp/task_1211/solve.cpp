#include <stdio.h>

bool treesDown(
	const long long n,
	const long long a,
	const long long aSkip,
	const long long b,
	const long long bSkip,
	long long need
) {

	long long aTreesSkip = n / aSkip * a;
	long long bTreesSkip = n / bSkip * b;
	need += aTreesSkip + bTreesSkip;
	long long sum = a + b;
	long long wannaSum = (need + n - 1) / n;
	return sum >= wannaSum;
}

long long binSearch(
	const long long n,
	const long long a,
	const long long aSkip,
	const long long b,
	const long long bSkip,
	const long long need
) {
	long long left = 1;
	long long right = n;
	while (left < right) {
		long long mid = (left + right) >> 1;

		if (treesDown(mid, a, aSkip, b, bSkip, need)) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long a, aSkip, b, bSkip, need;
	scanf("%lld %lld %lld %lld %lld", &a, &aSkip, &b, &bSkip, &need);
	const long long n = (long long)1e18 / (a + b) * 4;
	printf("%lld", binSearch(n, a, aSkip, b, bSkip, need));
	return 0;
}