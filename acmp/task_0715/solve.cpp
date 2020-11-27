#include <stdio.h>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<char>> a(sizeI, std::vector<char>(sizeJ));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            char c;
            scanf(" %c", &c);
            if (c == a[i][j]) {
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}