#include <stdio.h>
#include <algorithm>
#include <cmath>

const double PI = std::acos(-1);

double toRadian(double value) {
    return value * PI / 180;
}

struct Vector {

    double x;

    double y;

    double z;

    static Vector getPosition(double r, double w, double h) {
        w = toRadian(w);
        h = toRadian(h);
        double x = r * std::cos(w) * std::cos(h);
        double y = r * std::cos(w) * std::sin(h);
        double z = r * std::sin(w);
        return Vector{ x, y, z };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    double r, wStart, hStart, wEnd, hEnd;
    scanf("%lf %lf %lf %lf %lf", &r, &wStart, &hStart, &wEnd, &hEnd);
    Vector start = Vector::getPosition(r, wStart, hStart);
    Vector end = Vector::getPosition(r, wEnd, hEnd);
    Vector dist = Vector{ start.x - end.x, start.y - end.y, start.z - end.z };
    double D = std::min(r * 2, std::sqrt(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z));
    double angle;
    if (D == r * 2) {
        angle = PI;
    } else {
        angle = 2 * std::asin(D / 2 / r);
    }
    printf("%.2lf", r * angle);
    return 0;
}
