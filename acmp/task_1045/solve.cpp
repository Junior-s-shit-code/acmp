#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int INF = 5000;
	int n;
	scanf("%d", &n);
	std::vector<int> a(n + 1, INF);
	a[1] = 1;
	for (int num = 2; num <= n; num++) {
		for (int prev = num - 1; prev >= 1; prev--) {
			if (num % prev == 0) {
				int d = num / prev;
				a[num] = std::min(a[num], a[prev] + a[d]);
			}
			a[num] = std::min(a[num], a[prev] + num - prev);
		}
	}
	printf("%d", a[n]);
	return 0;
}