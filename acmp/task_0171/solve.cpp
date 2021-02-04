#include <stdio.h>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int maxDivisors = 1000;;
    long long num;
    scanf("%lld", &num);
    long long ans = 1;
    for (int d = 2; d < maxDivisors; d++) {
        int count = 1;
        while (num % d == 0) {
            num /= d;
            count++;
        }
        ans *= count;
    }
    printf("%lld", ans);
    return 0;
}