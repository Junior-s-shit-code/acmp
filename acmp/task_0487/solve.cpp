#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, maxTake, nMoves;
    scanf("%d %d %d", &n, &maxTake, &nMoves);
    for (int i = 0; i < nMoves; i++) {
        int curMove;
        scanf("%d", &curMove);
        if (n % (maxTake + 1) != 0 && curMove != n % (maxTake + 1)) {
            printf("F\n");
        } else {
            printf("T\n");
        }
        n -= curMove;
    }
    return 0;
}