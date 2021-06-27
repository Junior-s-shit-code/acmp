#include <stdio.h>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::vector<int> tenPow(10, 1);
    for (int i = 1; i < 10; i++) {
        tenPow[i] = tenPow[i - 1] * 10;
    }
    const int MAX_LEN = 50000;
    int n, maxNum, ansModDigits;
    scanf("%d %d %d", &n, &maxNum, &ansModDigits);
    long long mod = 1;
    for (int i = 0; i < ansModDigits; i++) {
        mod *= 10;
    }
    std::vector<long long> ans(n + 1, 0);
    ans[0] = 1;
    std::vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        char c;
        scanf(" %c", &c);
        a[i] = c - '0';
        long long value = 0;
        for (int j = 0; j < std::min(10, i); j++) {
            if (j > 0 && a[i - j] == 0) {
                continue;
            }
            value = 1LL * tenPow[j] * a[i - j] + value;
            if (value <= maxNum) {
                ans[i] += ans[i - j - 1];
                ans[i] %= mod;
            } else {
                break;
            }
        }
    }
    printf("%lld", ans[n]);
    return 0;
}