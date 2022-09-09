#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c, d, size;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &size);
    int minAns = 4;
    if (d + c <= size && d + b <= size) {
        minAns = 1;
    } else if (c + b <= size && c + a <= size) { // or d + a, but c + a <= d + a
        minAns = 2;
    } else if (a + b <= size) {
        minAns = 3;
    } 
    printf("%d", minAns);
    return 0;
}