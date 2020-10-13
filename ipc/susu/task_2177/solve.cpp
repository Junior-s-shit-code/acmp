#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>

struct Point {

    int x;

    int y;

    static Point read() {
        int x, y;
        scanf("%d %d", &x, &y);
        return Point{ x, y };
    }

    double distTo(const Point &second) const {
        int dx = x - second.x;
        int dy = y - second.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = Point::read();
    }
    double bestDist = (double)1e9;
    int ans1, ans2;
    for (int capital1 = 1; capital1 < n; capital1++) {
        for (int capital2 = 0; capital2 < capital1; capital2++) {
            Point c1 = p[capital1];
            Point c2 = p[capital2];
            double curDist = 0;
            for (int i = 0; i < n; i++) {
                double d1 = c1.distTo(p[i]);
                double d2 = c2.distTo(p[i]);
                curDist += std::min(d1, d2);
            }
            if (curDist < bestDist) {
                bestDist = curDist;
                ans1 = capital1;
                ans2 = capital2;
            }
        }
    }
    if (ans1 > ans2) {
        std::swap(ans1, ans2);
    }
    printf("%d %d", ans1 + 1, ans2 + 1);
    return 0;
}