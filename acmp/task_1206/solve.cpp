#include <stdio.h>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int minS, maxS, minP, maxP;
    scanf("%d %d %d %d", &minS, &maxS, &minP, &maxP);
    long long ans = 0;
    for (int x = 1; x * x <= maxS; x++) {
        int minY = std::max({ x, (minS + x - 1) / x, (minP + 1) / 2 - x});
        int maxY = std::min(maxS / x, maxP / 2 - x);
        if (minY <= maxY) {
            ans += 0LL + maxY - minY + 1;
        }
    }
    printf("%lld", ans);
    return 0;
}