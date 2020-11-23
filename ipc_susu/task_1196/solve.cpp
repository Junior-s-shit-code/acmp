#include <stdio.h>
#include <algorithm>
#include <vector>

struct Point {

	int x;

	int y;

	long long dist;

	static Point read() {
		int x, y;
		scanf("%d %d", &x, &y);
		return Point{ x, y, 0};
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nPoints;
	scanf("%d", &nPoints);
	std::vector<Point> p0(nPoints);
	for (int i = 0; i < nPoints; i++) {
		p0[i] = Point::read();
	}

	long long ans = 0;
	for (int iTopPoint = 0; iTopPoint < nPoints; iTopPoint++) {
		std::vector<Point> p(nPoints);
		for (int i = 0; i < nPoints; i++) {
			long long x = p0[i].x - p0[iTopPoint].x;
			long long y = p0[i].y - p0[iTopPoint].y;
			p[i] = Point{ (int) x, (int) y, x * x + y * y };
		}
		std::sort(p.begin(), p.end(), [](const Point &left, const Point &right) {
			return left.dist < right.dist;
		});
		int groupSize = 1;
		for (int i = 1; i <= nPoints; i++) {
			if (i < nPoints && p[i].dist == p[i - 1].dist) {
				groupSize++;
				for (int j = i - 1; j >= 0 && p[i].dist == p[j].dist; j--) {
					if (p[i].x * p[j].y - p[i].y * p[j].x == 0) {
						ans--;
						break;
					}
				}
			} else {
				ans += groupSize * (groupSize - 1) / 2;
				groupSize = 1;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}