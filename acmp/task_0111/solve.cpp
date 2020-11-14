#include <stdio.h>
#include <algorithm>


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k;
    scanf("%d", &k);

    int bestDivisor = 1;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            {
                int divisor = i;
                if (divisor >= 3) {
                    bestDivisor = divisor;
                    break;
                }
            }
            {
                int divisor = k / i;
                if (divisor >= 3) {
                    bestDivisor = divisor;
                }
            }
        }
    }
    printf("%d", bestDivisor - 1);
    return 0;
}