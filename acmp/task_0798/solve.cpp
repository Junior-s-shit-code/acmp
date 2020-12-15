#include <stdio.h>
#include <string>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int BLACK = 0;
    int sizeI, sizeJ, i, j, type;
    scanf("%d %d %d %d %d", &sizeI, &sizeJ, &i, &j, &type);
    if (((sizeI * sizeJ) & 1) == 1) {
        if (((i + j) & 1) == type) {
            printf("black");
        } else {
            printf("white");
        }
    } else {
        printf("equal");
    }
    return 0;
}