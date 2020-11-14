#include <stdio.h>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int s1 = a * b + c * d;
    int s2 = a * c + b * d;
    int s3 = a * d + b * c;
    printf("%d", std::max({ s1, s2, s3 }));
    return 0;
}