#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans = c;
    if (1LL * c / b * (b + a - 1) < c) {
        ans = (c / b + 1) * b;
    }
    printf("%d", ans);
    return 0;
}