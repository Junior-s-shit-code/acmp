#include <stdio.h>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int SIZE = 5;
    std::vector<std::vector<bool>> field(SIZE, std::vector<bool>(SIZE, false));
    int nQ;
    scanf("%d", &nQ);
    int ans = 0;
    for (int q = 0; q < nQ; q++) {
        int i, j;
        scanf("%d %d", &i, &j);
        i--;
        j--;
        field[i][j] = true;
        bool isVertical = true;
        bool isHorizontal = true;
        for (int k = 0; k < SIZE; k++) {
            isVertical &= field[k][j];
            isHorizontal &= field[i][k];
        }
        if (isVertical) {
            ans++;
            for (int k = 0; k < SIZE; k++) {
                field[k][j] = false;
            }
        }
        if (isHorizontal) {
            ans++;
            for (int k = 0; k < SIZE; k++) {
                field[i][k] = false;
            }
        }
    }
    printf("%d", ans);
    return 0;
}