#include <stdio.h>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nStation, nWays;
    scanf("%d %d", &nStation, &nWays);
    std::vector <int> way(nWays);
    for (int i = 0; i < nWays; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        from--;
        to--;
        way[i] = (1 << from) | (1 << to);
    }
    int best = nStation;
    int bestCount = 0;
    int bestCode = -1;

    for (int code = 0; code < (1 << nStation); code++) {
        bool isOk = true;
        for (int iWay = 0; iWay < nWays; iWay++) {
            if ((code & way[iWay]) == 0) {
                isOk = false;
                break;
            }
        }
        if (isOk) {
            int curBest = __builtin_popcount(code);
            if (curBest < best) {
                best = curBest;
                bestCount = 0;
                bestCode = code;
            }
            if (curBest == best) {
                bestCount++;
            }
        }
    }

    printf("%d %d\n", best, bestCount);
    for (int i = 0; i < nStation; i++) {
        if (bestCode & (1 << i)) {
            printf("%d ", i + 1);
        }
    }
    return 0;
}