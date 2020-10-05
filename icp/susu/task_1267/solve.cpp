#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", (b + 12 - a) % 12);
    return 0;
}