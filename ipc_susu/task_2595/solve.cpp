#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += std::abs(a[i] - b[i]);
    }
    printf("%d", ans);
    return 0;
}