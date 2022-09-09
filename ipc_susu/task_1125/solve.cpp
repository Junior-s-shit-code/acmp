#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count += 2;
            if (i * i == n) {
                count--;
            }
        }
    }

    printf("%d", count);
    return 0;
}