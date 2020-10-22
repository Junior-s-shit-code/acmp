#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	long long ans = 0;
	long long leftSum = 0;
	for (int i = 0; i < n - 1; i++) {
		leftSum += a[i] * a[i];
		sum -= a[i];
		ans = std::max(ans, 1LL * leftSum * sum);
	}
	printf("%lld", ans);
	return 0;
}