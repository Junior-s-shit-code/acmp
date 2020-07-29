#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end());
    long long curSum = 1;
    for (int i = 0; i < n; i++) {
        if (curSum < a[i]) {
            break;
        }
        curSum += a[i];
    }
    printf("%lld", curSum);
    return 0;
}