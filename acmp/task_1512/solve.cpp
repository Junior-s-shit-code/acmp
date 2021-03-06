#include <stdio.h>
#include <algorithm>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long left, right, maxDiff;
    scanf("%lld %lld %lld", &left, &right, &maxDiff);
    long long ans = 0;
    for (long long a = 1; a <= (int)1e6; a++) {
        if (a * a * a < left) {
            continue;
        }
        if (a * a * a > right) {
            break;
        }
        long long maxValue2 = std::min(right, a * a * a + maxDiff);
        long long minValue2 = std::max(left, a * a * a - maxDiff);
        long long max = (long long)std::sqrt(maxValue2) + 1;
        while (max * max > maxValue2) {
            max--;
        }
        long long min = (long long)std::sqrt(minValue2) - 1;
        while (min * min < minValue2) {
            min++;
        }
        ans += max - min + 1;
    }
    printf("%lld", ans);
    return 0;
}