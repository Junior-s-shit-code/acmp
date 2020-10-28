#include <stdio.h>
#include <vector>
#include <algorithm>

void solve(long long n, long long dist, long long &x, long long &y) {
	long long n2 = (n >> 1);
	if (n == 1) {
		x = 1;
		y = 1;
	} else {
		if (dist <= n2 * n2) {
			solve(n >> 1, dist, y, x);
		} else if (dist <= 2 * n2 * n2) {
			solve(n >> 1, dist - n2 * n2, x, y);
			y += n2;
		} else if (dist <= n2 * n2 * 3) {
			solve(n >> 1, dist - n2 * n2 * 2, x, y);
			y += n2;
			x += n2;
		} else {
			solve(n >> 1, dist - 3 * n2 * n2, y, x);
			y = n2 + 1 - y;
			x = n + 1 - x;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long n, dist, x = 1, y = 1;
	scanf("%lld %lld", &n, &dist);
	solve(n, dist, x, y);
	printf("%lld %lld", x, y);
	return 0;
}