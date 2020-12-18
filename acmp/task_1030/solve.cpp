#include <stdio.h>
#include <algorithm>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    long double sum = std::min(a, b) + std::min(c, d);
    printf("%d", int(std::sqrt(sum)));
    return 0;
}