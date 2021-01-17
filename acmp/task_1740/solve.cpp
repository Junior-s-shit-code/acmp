#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long diff;
    scanf("%lld", &diff);
    long long x = -1;
    long long y = -1;
    if (diff == 0) {
        x = 1;
        y = 1;
    } else if (diff % 2 == 1) {
        x = (diff + 1) / 2;
        y = (diff - 1) / 2;
    } else if (diff % 4 == 0) {
        x = diff / 4 + 1;
        y = diff / 4 - 1;
    }

    if (x > 0 && y > 0) {
        printf("Yes\n%lld %lld", x, y);
    } else {
        printf("No");
    }
    return 0;
}