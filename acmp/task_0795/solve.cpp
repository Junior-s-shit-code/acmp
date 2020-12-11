#include <stdio.h>
#include <algorithm>
#include <vector>

// O(n)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int minSpeed, maxSpeed, slowdown;
    scanf("%d %d %d", &minSpeed, &maxSpeed, &slowdown);
    int iStart = (minSpeed - 1) / slowdown;
    int iEnd = (maxSpeed - 1) / slowdown;
    int maxWin = 0;
    for (int i = 0; i < std::min(n, iEnd - iStart + 1); i++) {
        maxWin = std::max({ maxWin, a[(iStart + i) % n], a[(n - (iStart + i) % n) % n] });
    }
    printf("%d", maxWin);
    return 0;
}