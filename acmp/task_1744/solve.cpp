#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int value;
        scanf("%d", &value);
        pref[i] = pref[i - 1] + value;
    }
    long long sum = pref[n];
    long long minDiff = (long long)1e18;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        long long right = sum - pref[i];
        long long left = pref[i];
        long long diff = right - left;
        if (std::abs(diff) < minDiff) {
            minDiff = diff;
            ans = i;
        }
    }
    printf("%d", ans);
    return 0;
}