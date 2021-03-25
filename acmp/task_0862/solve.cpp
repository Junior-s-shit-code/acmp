#include <stdio.h>
#include <algorithm>

long long getSum(long long a) {
	return a * (a + 1) / 2;
}

long long getLeftSum(long long n, long long m) {
	long long divN = n / m;
	long long modN = n % m;
	return divN * getSum(m - 1) + getSum(modN);
}

long long getRightSum(long long n, long long m) {
	long long limit = std::min(n, m);
	long long sum = 0;
	long long minVal = limit;
	for (long long i = 1; i <= m / i; i++) {
		long long start = m / (i + 1);
		long long end = std::min(m / i, limit);
		if (start >= end) {
			continue;
		}
		minVal = start;
		long long curSum = getSum(end) - getSum(start);
		sum += curSum * i;
	}
	for (int i = 1; i <= minVal; i++) {
		sum += m / i * i;
	}
	return n * m - sum;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long n, m;
	scanf("%lld %lld", &n, &m);
	printf("%lld", getLeftSum(n, m) + getRightSum(n, m));
	return 0;
}