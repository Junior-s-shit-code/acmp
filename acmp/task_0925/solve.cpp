#include <stdio.h>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int type, n, a, b, c;
    scanf("%d %d %d %d %d", &type, &n, &a, &b, &c);
    if (type == 1) {
        printf("%d", std::max(0, a + b + c - 2 * n));
    } else {
        printf("%d", std::min({ a, b, c }));
    }
    return 0;
}