#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, nQ, r;
    scanf("%d %d %d", &n, &nQ, &r);
    const long long MOD = 2147483647;
    const int modN = n - 1;
    long long curR31;
    long long prevR31 = r;
    std::vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        curR31 = (prevR31 * 1103515245 + 12345) & MOD;
        a[i] = (int) (curR31 >> 16);
        prevR31 = curR31;
    }

    std::vector <int> kPlus(n + 1, 0);
    std::vector <int> kMinus(n + 1, 0);

    for (int q = 0; q < nQ; q++) {
        prevR31 = (prevR31 * 1103515245 + 12345) & MOD;
        curR31 = (prevR31 * 1103515245 + 12345) & MOD;
        int curR15 = (int) (prevR31 >> 16);
        int nextR15 = (int) (curR31 >> 16);
        int left = std::min(curR15 & modN, nextR15 & modN) + 1;
        int right = std::max(curR15 & modN, nextR15 & modN) + 1;
        kPlus[left]++;
        kMinus[right]++;

        prevR31 = curR31;
    }

    int curK = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        curK += kPlus[i];
        ans += 1LL * curK * a[i];
        ans &= MOD;
        curK -= kMinus[i];
    }
    printf("%lld", ans);
    return 0;
}