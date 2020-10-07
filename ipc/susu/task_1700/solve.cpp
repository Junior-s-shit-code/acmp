#include <stdio.h>
#include <vector>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    int maxH = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > maxH) {
            maxH = a[i];
            index = i;
        }
    }
    int ans = 0;
    int curH = 0;
    for (int i = 0; i <= index; i++) {
        ans += std::abs(a[i] - curH);
        ans++;
        curH = a[i];
    }
    printf("%d", ans - 1);
    return 0;
}