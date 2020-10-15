#include <stdio.h>
#include <algorithm>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int h, m;
    scanf("%d %d", &h, &m);
    int a = (h % 12) * 5 + m / 12;
    int b = m;
    int value = std::abs(a - b);
    int ans = std::min(value, 60 - value);
    printf("%d", ans * 6);
    return 0;
}