#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

struct Point {

    int x;

    int y;

    int z;
    
    static Point read() {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        return Point{ x, y, z };
    }

    double distTo(const Point &second) const {
        int dx = x - second.x;
        int dy = y - second.y;
        int dz = z - second.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
};

struct Hole {

    Point p1;

    Point p2;

    static Hole read() {
        Point p1 = Point::read();
        Point p2 = Point::read();
        return Hole{ p1, p2 };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nHoles;
    scanf("%d", &nHoles);
    Point start = Point::read();
    Point end = Point::read();
    std::vector<Hole> holes(nHoles);
    for (int i = 0; i < nHoles; i++) {
        holes[i] = Hole::read();
    }
    std::vector<std::vector<double>> len(nHoles, std::vector<double>(nHoles, (double)1e9));
    for (int i = 0; i < nHoles; i++) {
        for (int j = 0; j < nHoles; j++) {
            double d1 = std::min(holes[i].p1.distTo(holes[j].p1),
                                 holes[i].p2.distTo(holes[j].p1));
            double d2 = std::min(holes[i].p1.distTo(holes[j].p2),
                                 holes[i].p2.distTo(holes[j].p2));
            len[i][j] = std::min(d1, d2);
        }
    }
    for (int iMidHole = 0; iMidHole < nHoles; iMidHole++) {
        for (int iFirstHole = 0; iFirstHole < nHoles; iFirstHole++) {
            for (int iSecondHole = 0; iSecondHole < nHoles; iSecondHole++) {
                if (len[iFirstHole][iSecondHole] > len[iFirstHole][iMidHole] + len[iMidHole][iSecondHole]) {
                    len[iFirstHole][iSecondHole] = len[iFirstHole][iMidHole] + len[iMidHole][iSecondHole];
                }
            }
        }
    }
    double minDist = start.distTo(end);
    for (int i = 0; i < nHoles; i++) {
        for (int j = 0; j < nHoles; j++) {
            double d1 = std::min(start.distTo(holes[i].p1),
                                 start.distTo(holes[i].p2));
            double d2 = std::min(end.distTo(holes[j].p1),
                                 end.distTo(holes[j].p2));
            minDist = std::min(minDist, d1 + len[i][j] + d2);
        }
    }
    printf("%lf", minDist);
    return 0;
}