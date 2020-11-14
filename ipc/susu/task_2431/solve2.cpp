#include <stdio.h>
#include <vector>
#include <algorithm>

void d2xy(const int n, int dist, int &x, int &y) {
	for (int step = 1; step < n; step <<= 1) {
		int rx = 1 & (dist >> 1);
		int ry = 1 & (dist ^ rx);
		//rotate
		if (ry == 0) {
			if (rx == 1) {
				x = step - 1 - x;
				y = step - 1 - y;
			}
			std::swap(x, y);
		}
		x += step * rx;
		y += step * ry;
		dist >>= 2;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, dist;
	scanf("%d %d", &n, &dist);
	dist--;
	int x = 0, y = 0;
	d2xy(n, dist, x, y);
	printf("%d %d", x + 1, y + 1);
	return 0;
}