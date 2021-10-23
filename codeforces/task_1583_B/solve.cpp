#include <stdio.h>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nT;
    scanf("%d", &nT);
    for (int t = 0; t < nT; t++) {
        int nV, nE;
        scanf("%d %d", &nV, &nE);
        std::vector<bool> root(nV, true);
        for (int i = 0; i < nE; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            root[b - 1] = false;
        }
        int vRoot = -1;
        for (int i = 0; i < nV; i++) {
            if (root[i]) {
                vRoot = i + 1;
            }
        }
        for (int i = 1; i <= nV; i++) {
            if (i == vRoot) {
                continue;
            }
            printf("%d %d\n", vRoot, i);
        }
    }
    return 0;
}