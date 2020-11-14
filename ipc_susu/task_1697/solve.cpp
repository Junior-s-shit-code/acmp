#include <stdio.h>
#include <vector>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, prevValue;
    scanf("%d %d", &n, &prevValue);
    int ans;
    int maxDiff = -1;
    for (int i = 1; i < n; i++) {
        int curValue;
        scanf("%d", &curValue);
        int diff = std::abs(prevValue - curValue);
        if (diff > maxDiff) {
            ans = i + 1;
            maxDiff = diff;
        }
        prevValue = curValue;
    }
    printf("%d", ans);
    return 0;
}