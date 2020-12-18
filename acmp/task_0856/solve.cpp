#include <stdio.h>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MULT = 1000;
    int rPin, n;
    scanf("%d %d", &rPin, &n);
    const int BORDER = n + 1;
    int rBall;
    scanf("%d", &rBall);
    int x0, y0;
    scanf("%d %d", &x0, &y0);
    x0 *= MULT;
    y0 *= MULT;
    int vx, vy;
    scanf("%d %d", &vx, &vy);
    vx *= MULT;
    vy *= MULT;
    int right = BORDER;
    int left = -BORDER;
    long long ans = 0;
    for (int y = 0; y < MULT * n; y += MULT) {
        while (true) {
            if (left == -BORDER) {
                break;
            }
            int x = left * MULT;
            if (1LL * vx * (y - y0) - 1LL * vy * (x - x0) <= 0) {
                left--;
                continue;
            }
            int a = vy;
            int b = -vx;
            long long c = 1LL * vx * y0 - 1LL * x0 * vy;
            // ax + by + c = 0
            // |ax + by + c|/sqrt(a^2 + b^2) <= rPin + rBall
            // (ax+by+c)^2 <= (rPin + rBall)^2 * (a^2 + b^2)

            long double axbyc = 1LL * a * x + 1LL * b * y + c;
            long double a2b2 = 1LL * a * a + 1LL * b * b;
            long double rProd = 1LL * (rPin + rBall) * (rPin + rBall);
            if (axbyc * axbyc <= rProd * a2b2) {
                left--;
            } else {
                break;
            }
        }
        while (true) {
            if (left == BORDER) {
                break;
            }
            int x = (left + 1) * MULT;
            if (1LL * vx * (y - y0) - 1LL * vy * (x - x0) <= 0) {
                break;
            }
            int a = vy;
            int b = -vx;
            long long c = 1LL * vx * y0 - 1LL * x0 * vy;
            long double axbyc = 1LL * a * x + 1LL * b * y + c;
            long double a2b2 = 1LL * a * a + 1LL * b * b;
            long double rProd = 1LL * (rPin + rBall) * (rPin + rBall);
            if (axbyc * axbyc <= rProd * a2b2) {
                break;
            } else {
                left++;
            }
        }
        // right
        while (true) {
            if (right == BORDER) {
                break;
            }
            int x = right * MULT;
            if (1LL * vx * (y - y0) - 1LL * vy * (x - x0) >= 0) {
                right++;
                continue;
            }
            int a = vy;
            int b = -vx;
            long long c = 1LL * vx * y0 - 1LL * x0 * vy;
            long double axbyc = 1LL * a * x + 1LL * b * y + c;
            long double a2b2 = 1LL * a * a + 1LL * b * b;
            long double rProd = 1LL * (rPin + rBall) * (rPin + rBall);
            if (axbyc * axbyc <= rProd * a2b2) {
                right++;
            } else {
                break;
            }
        }
        while (true) {
            if (right == -BORDER) {
                break;
            }
            int x = (right - 1) * MULT;
            if (1LL * vx * (y - y0) - 1LL * vy * (x - x0) >= 0) {
                break;
            }
            int a = vy;
            int b = -vx;
            long long c = 1LL * vx * y0 - 1LL * x0 * vy;
            long double axbyc = 1LL * a * x + 1LL * b * y + c;
            long double a2b2 = 1LL * a * a + 1LL * b * b;
            long double rProd = 1LL * (rPin + rBall) * (rPin + rBall);
            if (axbyc * axbyc <= rProd * a2b2) {
                break;
            } else {
                right--;
            }
        }
        int leftIn = left + 1;
        int rightIn = right - 1;
        if (leftIn > y / MULT || rightIn < -y / MULT) {
            continue;
        }
        if (y / 1000 % 2 == 0) {
            if (leftIn % 2 != 0) {
                leftIn++;
            }
            if (rightIn % 2 != 0) {
                rightIn--;
            }
        } else {
            if (leftIn % 2 == 0) {
                leftIn++;
            }
            if (rightIn % 2 == 0) {
                rightIn--;
            }
        }
        rightIn = std::min(rightIn, y / 1000);
        leftIn = std::max(leftIn, -y / 1000);
        if (leftIn <= rightIn) {
            ans += (rightIn - leftIn) / 2 + 1;
        }
    }
    printf("%lld", ans);
    return 0;
}