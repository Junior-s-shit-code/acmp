#include <stdio.h>
#include <cmath>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int diff1 = std::abs(a - b);
    int diff2 = std::abs(b - c);
    int diff3 = std::abs(a - c);
    if (std::max({ diff1, diff2, diff3 }) <= 25) {
        printf("ALLOWED");
    } else {
        printf("FORBIDDEN");
    }
    return 0;
}