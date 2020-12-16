#include <stdio.h>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<std::vector<char>> a(n, std::vector<char>(n));
    int all = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'C') {
                all++;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (2 * count < all) {
                printf("1");
            } else {
                printf("2");
            }

            if (a[i][j] == 'C') {
                count++;
            }
        }
        printf("\n");
    }
    return 0;
}