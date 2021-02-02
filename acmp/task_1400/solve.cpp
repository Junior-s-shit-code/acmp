#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int a, b, c;
    b = n / 3;
    if (n % 3 == 0) {
        a = b - 1;
        c = b + 1;
    } else if (n % 3 == 1) {
        a = b - 1;
        c = b + 2;
    } else {
        a = b - 1;
        c = b + 2;
        b++;
    }
    printf("%d %d %d", a, b, c);
    return 0;
}