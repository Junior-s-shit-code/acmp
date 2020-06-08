#include <stdio.h>
#include <cmath>

int fact(int n) {
    if (n == 0) {
        return 1;
    } else {
        return fact(n - 1) * n;
    }
}

int subFact(int n) {
    if (n == 0) {
        return 1;
    }
    int sum = 0;
    int p = fact(n);
    for (int i = 2; i <= n; i++) {
        p /= i;
        sum += p;
        p = -p;
    }
    return sum;
}

int combination(int n, int k) {
    return fact(n) / (fact(k) * fact(n - k));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", combination(n, k) * subFact(n - k));
    return 0;
}