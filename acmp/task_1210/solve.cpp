#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("%d", n * (n - 2));
    } else {
        printf("%d", n * (n - 1));
    }
    return 0;
}