#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    if (n % 4 == 0) {
        printf("0");
    } else if (n % 8 == 1 || n % 8 == 2 || n % 8 == 7) {
        printf("1");
    } else {
        printf("2");
    }
    return 0;
}