#include <stdio.h>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long num;
    scanf("%lld", &num);
    long long ans = 1;
    for (int d = 2; d < 1000; d++) {
        int count = 0;
        while (num % d == 0) {
            num /= d;
            count++;
        }
        ans *= std::max(1, count);
    }
    printf("%lld", ans);
    return 0;
}