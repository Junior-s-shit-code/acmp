#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>

inline long long calc31(const long long prev, const int MOD) {
    return (prev * 1103515245 + 12345) & MOD;
}

inline int reduction(long long value) {
    return (int)(value >> 16);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, nQ, r;
    scanf("%d %d %d", &n, &nQ, &r);
    const long long MOD = (1 << 31) - 1;
    const int modN = n - 1;
    long long curR31;
    long long prevR31 = r;
    std::vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        curR31 = calc31(prevR31, MOD);
        a[i] = reduction(curR31);
        prevR31 = curR31;
    }

    std::vector <int> updateSegments(n + 2, 0);

    for (int q = 0; q < nQ; q++) {
        prevR31 = calc31(prevR31, MOD);
        curR31 = calc31(prevR31, MOD);
        int curR15 = reduction(prevR31);
        int nextR15 = reduction(curR31);
        int left = std::min(curR15 & modN, nextR15 & modN) + 1;
        int right = std::max(curR15 & modN, nextR15 & modN) + 1;
        updateSegments[left]++;
        updateSegments[right + 1]--;

        prevR31 = curR31;
    }

    int curK = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        curK += updateSegments[i];
        ans += 1LL * curK * a[i];
        ans &= MOD;
    }
    printf("%lld", ans);
    return 0;
}