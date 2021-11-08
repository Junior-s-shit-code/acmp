#include <stdio.h>
#include <algorithm>

bool isPrime(int num) {
    for (int d = 2; d <= num / d; d++) {
        if (num % d == 0) {
            return false;
        }
    }
    return num > 1;
}

void solveTest() {
    int sum = 0;
    int minOdd = (int)1e9;
    int n;
    int iNum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        sum += value;
        if ((value & 1) > 0) {
            minOdd = value;
            iNum = i + 1;
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
            if (i != iNum) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nT;
    scanf("%d", &nT);
    for (int t = 0; t < nT; t++) {
        solveTest();
    }
    return 0;
}