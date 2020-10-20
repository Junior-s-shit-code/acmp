#include <stdio.h>
#include <algorithm>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int ans;
	if (((c <= a && a <= d) || (c >= a && a >= d)) && ((a < b && c < d) || (a > b && c > d))) {
		if ((c <= b && b <= d) || (c >= b && b >= d)) {
			ans = std::abs(a - c) + std::abs(b - a) + 2;
		} else {
			ans = std::abs(a - c) + std::abs(d - a) + std::abs(b - d) + 3;
		}
	} else {
		ans = std::abs(d - c) + std::abs(a - d) + std::abs(b - a) + 3;
	}
	if (a == d) {
		ans--;
	}
	printf("%d", ans);
	return 0;
}