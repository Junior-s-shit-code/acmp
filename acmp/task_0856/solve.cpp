#include <stdio.h>
#include <algorithm>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int rPin, n;
    scanf("%d %d", &rPin, &n);
    int rBall;
    scanf("%d", &rBall);
    int x0, y0;
    scanf("%d %d", &x0, &y0);
    int vx, vy;
    scanf("%d %d", &vx, &vy);
    long long ans = 0;
    double k = 1.0 * vx / vy;
    double c = 1.0 * (rBall + rPin) / 1000 * std::sqrt(1LL * vx * vx + 1LL * vy * vy) / vy;
    for (int yPin = 0; yPin < n; yPin++) {
        double l = 1.0L * k * (yPin - y0) - c + x0;
        double r = 1.0L * k * (yPin - y0) + c + x0;
        int left = (int) std::ceil(l);
        int right = (int) std::floor(r);
        if (std::abs(left) % 2 != yPin % 2) {
            left++;
        } 
        if (std::abs(right) % 2 != yPin % 2) {
            right--;
        }
        left = std::max(left, -yPin);
        right = std::min(right, yPin);

        ans += std::max(0, (right - left) / 2 + 1);
    }
    printf("%lld", ans);
    return 0;
}