#include <stdio.h>
#include <algorithm>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long minX, minY, maxX, maxY;
	scanf("%lld %lld %lld %lld", &minX, &minY, &maxX, &maxY);
	long long xc, yc, r;
	scanf("%lld %lld %lld", &xc, &yc, &r);
	minX -= xc;
	minY -= yc;
	maxX -= xc;
	maxY -= yc;
	long long ans = 0;
	long long y = 0;
	for (long long x = -r; x <= r; x++) {
		while (x * x + (y + 1) * (y + 1) <= r * r) {
			y++;
		}
		while (x * x + y * y > r * r) {
			y--;
		}
		if (minX <= x && x <= maxX) {
			ans += std::max(0LL, std::min(maxY, y) - std::max(minY, -y) + 1);
		}
	}
	printf("%lld", ans);
	return 0;
}