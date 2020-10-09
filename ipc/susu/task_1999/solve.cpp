#include <stdio.h>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans;
    if (b - a == d - c) {
        ans = a - c;
    } else {
        ans = a + c;
    }
    printf("%d", ans);
    return 0;
}