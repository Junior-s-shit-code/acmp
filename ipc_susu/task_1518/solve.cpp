#include <stdio.h>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += std::sqrt(i);
    }
    printf("%lf", ans);
    return 0;
}