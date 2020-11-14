#include <stdio.h>
#include <vector>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int leftIndex = 1; //leftIndex
    long long ans = 0;
    while (leftIndex <= n) {
        int addValue = n / leftIndex;
        int rightIndex = n / addValue;
        ans += 1LL * addValue * (rightIndex - leftIndex + 1);
        leftIndex = rightIndex + 1;
    }
    printf("%lld", ans);
    return 0;
}