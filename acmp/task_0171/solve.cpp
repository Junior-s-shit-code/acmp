#include <stdio.h>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MAX_DIVISORS = 1000;
    long long num;
    scanf("%lld", &num);
    long long ans = 1;
    for (int d = 2; d < MAX_DIVISORS; d++) {
        int count = 0;
        while (num % d == 0) {
            num /= d;
            count++;
        }
        ans *= count + 1;
    }
    printf("%lld", ans);
    return 0;
}