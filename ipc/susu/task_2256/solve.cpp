#include <stdio.h>
#include <algorithm>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n;
    scanf("%lld", &n);
    long long ans = (long long)((std::sqrt(1 + 1.0L * 2 * (1.0 * n * n + n)) - 1) / 2);
    long long sum = (1 + n) * n / 2;
    long long sum1 = (1 + ans) * ans / 2;
    long long sum2 = (2 + ans) * (ans + 1) / 2;
    if (std::abs(sum - 2 * sum1) > std::abs(sum - 2 * sum2)) {
        ans++;
    }
    printf("%lld", ans);
    return 0;
}