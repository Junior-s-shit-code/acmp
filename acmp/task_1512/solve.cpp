#include <stdio.h>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld", std::max(0LL, 3 * a + b - c + 2) / 3);
    return 0;
}