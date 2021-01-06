#include <stdio.h>
#include <algorithm>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    long double sum = std::min(a, b) + std::min(c, d);
    long double sumSqrt = std::sqrt(sum);
    long long ans = sumSqrt + 1;
    while (ans * ans > sum) {
        ans--;
    }
    printf("%lld", ans);
    return 0;
}