#include <stdio.h>
#include <algorithm>

bool isPrime(int num) {
    for (int d = 2; d * d <= num; d++) {
        if (num % d == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int INF = (int)1e9;
    int nT;
    scanf("%d", &nT);
    for (int t = 0; t < nT; t++) {
        int sum = 0;
        int minOdd = INF;
        int n, value, index = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            sum += value;
            if ((value & 1) > 0) {
                minOdd = value;
                index = i + 1;
            }
        }
        if (!isPrime(sum)) {
            printf("%d\n", n);
            for (int i = 1; i <= n; i++) {
                printf("%d ", i);
            }
            printf("\n");
        } else {
            printf("%d\n", n - 1);
            for (int i = 1; i <= n; i++) {
                if (i != index) {
                    printf("%d ", i);
                }
            }
            printf("\n");
        }
    }
    return 0;
}