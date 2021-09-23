#include <stdio.h>
#include <algorithm>

struct Point {

    long long x;

    long long y;
};

long long area(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool intersect_1(long long a, long long b, long long c, long long d) {
    if (a > b) {
        std::swap(a, b);
    } 
    if (c > d) {
        std::swap(c, d);
    }
    return std::max(a, c) <= std::min(b, d);
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return intersect_1(p1.x, p2.x, p3.x, p4.x) &&
        intersect_1(p1.y, p2.y, p3.y, p4.y) &&
        area(p1, p2, p3) * area(p1, p2, p4) <= 0 &&
        area(p3, p4, p1) * area(p3, p4, p2) <= 0;

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, w, e;
    scanf("%d %d %d", &n, &w, &e);
    Point mainP1 = Point{ 0, w };
    Point mainP2 = Point{ 100 * n, e };
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            Point p1 = Point{ (i - 1) * 100, (j - 1) * 100};
            Point p2 = Point{ i * 100, j * 100 };
            Point p3 = Point{ (i - 1) * 100, j * 100 };
            Point p4 = Point{ i * 100, (j - 1) * 100 };
            if (intersect(mainP1, mainP2, p1, p2) || intersect(mainP1, mainP2, p3, p4)) {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}