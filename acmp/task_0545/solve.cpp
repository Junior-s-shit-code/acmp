#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::vector <double> a (3);
    scanf("%lf %lf %lf", &a[0], &a[1], &a[2]);
    std::sort(a.begin(), a.end());
    double alfa = std::acos((a[2] * a[2] + a[1] * a[1] - a[0] * a[0]) / (2 * a[1] * a[2]));
    const double PI = std::acos(-1);
    double s;
    if (alfa >= PI / 4) {
        s = a[2] * a[2] / 4;
    } else if (a[1] >= a[2] * std::cos(alfa)) {
        double leg1 = a[2] * std::cos(alfa);
        double leg2 = a[2] * std::sin(alfa);
        s = leg1 * leg2 / 2;
    } else {
        double leg1 = a[1];
        double leg2 = leg1 * std::tan(alfa);
        s = leg1 * leg2 / 2;
    }
    printf("%.5lf", s);
    return 0;
}