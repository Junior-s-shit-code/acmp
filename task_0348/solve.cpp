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

struct Segment {

	Point p1;

	Point p2;

	static Segment read() {
		Point p1 = Point::read();
		Point p2 = Point::read();
		return Segment{ p1, p2 };
	}
	
	bool intersectsWith(const Segment &second) const{
		return (isOkaySegments(p1.x, p2.x, second.p1.x, second.p2.x) &&
				isOkaySegments(p1.y, p2.y, second.p1.y, second.p2.y) &&
				getArea(p1, p2, second.p1) * getArea(p1, p2, second.p2) <= 0 && 
				getArea(second.p1, second.p2, p1) * getArea(second.p1, second.p2, p2) <= 0);
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	Segment s1 = Segment::read();
	Segment s2 = Segment::read();
	if (s1.intersectsWith(s2)) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}