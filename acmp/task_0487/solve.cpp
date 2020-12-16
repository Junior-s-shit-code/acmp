#include <stdio.h>

bool badMove(int n, int maxTake, int value) {
    if (n <= maxTake && value < n ||
        n % (maxTake + 1) != 0 && (n - value) % (maxTake + 1) != 0) {
        return true;
    } 
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, maxTake, nMoves;
    scanf("%d %d %d", &n, &maxTake, &nMoves);
    for (int i = 0; i < nMoves; i++) {
        int value;
        scanf("%d", &value);
        if (badMove(n, maxTake, value)) {
            printf("F\n");
        } else {
            printf("T\n");
        }
        n -= value;
    }
    return 0;
}