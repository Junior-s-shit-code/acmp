#include <stdio.h>

void prepareData(long long &a, const int value) {
    if (a % 2 == 1) {
        a = value;
    } else {
        a = 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b + c;
        if ((sum == a || sum == b || sum == c) && sum > 1) {
            printf("No\n");
            continue;
        }
        prepareData(a, 3);
        prepareData(b, 5);
        prepareData(c, 6);
        sum = a ^ b ^ c;
        if (sum == 3 || sum == 5 || sum == 6) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}