#include <stdio.h>
#include <algorithm>

struct Point {

	long long x;

	long long y;

	static Point read() {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		return Point{ x, y };
	}
};

long long getArea(Point p1, Point p2, Point p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) - 1LL * (p2.y - p1.y) * (p3.x - p1.x);
}

bool isOkaySegments(long long a, long long b, long long c, long long d) {
	if (a > b) {
		std::swap(a, b);
	}
	if (c > d) {
		std::swap(c, d);
	}
	return std::max(a, c) <= std::min(b, d);
}

bool isIntersect(Point p1, Point p2, Point p3, Point p4) {
	return (isOkaySegments(p1.x, p2.x, p3.x, p4.x) &&
			isOkaySegments(p1.y, p2.y, p3.y, p4.y) && 
			getArea(p1, p2, p3) * getArea(p1, p2, p4) <= 0 &&
			getArea(p3, p4, p1) * getArea(p3, p4, p2) <= 0);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	Point p1 = Point::read();
	Point p2 = Point::read();
	Point p3 = Point::read();
	Point p4 = Point::read();
	if (isIntersect(p1, p2, p3, p4)) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}