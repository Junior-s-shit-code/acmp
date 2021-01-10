#include <stdio.h>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b;
    scanf("%d %d", &a, &b);
    int max = std::max(a, b);
    int min = std::min(a, b);
    printf("%d %d", (max + 1) / 2, min);
    return 0;
}