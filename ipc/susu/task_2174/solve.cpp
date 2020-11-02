#include <stdio.h>
#include <cmath>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (std::max({ a, b, c }) - std::min({a, b, c}) <= 25) {
        printf("ALLOWED");
    } else {
        printf("FORBIDDEN");
    }
    return 0;
}