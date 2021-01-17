#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n;
    int k;
    scanf("%lld %d", &n, &k);
    int ans = 0;
    while (n >= k) {
        ans++;
        if (n % k == 0) {
            printf("%d", ans);
            return 0;
        }
        n = n - n / k;
    }
    printf("0");
    return 0;
}