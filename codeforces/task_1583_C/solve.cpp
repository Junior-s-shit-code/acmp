#include <stdio.h>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<bool>> a(sizeI, std::vector<bool>(sizeJ, false));
    std::vector<int> countBadColumn(sizeJ, 0);
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            char c;
            scanf(" %c", &c);
            a[i][j] = (c == '.');
        }
    }
    for (int j = 1; j < sizeJ; j++) {
        countBadColumn[j] = countBadColumn[j - 1];
        for (int i = 1; i < sizeI; i++) {
            if (!a[i - 1][j] && !a[i][j - 1]) {
                countBadColumn[j]++;
                break;
            }
        }
    }
    int nQ;
    scanf("%d", &nQ);
    for (int q = 0; q < nQ; q++) {
        int left, right;
        scanf("%d %d", &left, &right);
        if (countBadColumn[right - 1] - countBadColumn[left - 1] == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}