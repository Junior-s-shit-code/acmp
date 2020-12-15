#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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