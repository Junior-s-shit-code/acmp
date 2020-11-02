#include <stdio.h>
#include <algorithm>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int h, m;
    scanf("%d %d", &h, &m);
    int a = (h % 12) * 30 + (m / 12) * 6;
    int b = m * 6;
    int angle = std::abs(a - b);
    printf("%d", std::min(angle, 360 - angle));
    return 0;
}