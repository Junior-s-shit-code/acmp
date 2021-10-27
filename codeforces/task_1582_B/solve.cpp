#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nT;
    scanf("%d", &nT);
    for (int t = 0; t < nT; t++) {
        int n;
        scanf("%d", &n);
        int countZero = 0, countOne = 0;
        int val;
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            if (val == 0) {
                countZero++;
            } else if (val == 1) {
                countOne++;
            }
        }
        printf("%lld\n", countOne * (1LL << countZero));
    }
    return 0;
}