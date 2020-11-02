#include <stdio.h>


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int remainN = (1 << n) - a - b;
    int minCount = 0;
    int unusedBits = 1;
    for (int i = n; i >= 0; i--) {
        if (((a >> i) & 1) != 0) {
            unusedBits--;
        }
        if (((b >> i) & 1) != 0) {
            unusedBits--;
        }
        if (((remainN >> 1) & 1) != 0) {
            unusedBits--;
        }
        minCount += unusedBits;
        unusedBits <<= 1;
    }
    printf("%d", minCount);
    return 0;
}