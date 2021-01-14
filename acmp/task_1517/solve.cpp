#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nV, exp;
    scanf("%d %d", &nV, &exp);
    std::vector<int> parent(1 + nV);
    for (int i = 2; i <= nV; i++) {
        scanf("%d", &parent[i]);
    }
    std::vector<int> max(1 + nV, 0);
    std::vector<int> max2(1 + nV, 0);
    for (int i = nV; i >= 2; i--) {
        int newMax = max[i] + 1;
        int curParent = parent[i];
        if (newMax > max[curParent]) {
            max2[curParent] = max[curParent];
            max[curParent] = newMax;
        } else if (newMax > max2[curParent]) {
            max2[curParent] = newMax;
        }
    }
    long long h = 1LL + max[1];
    long long ans = h * exp;
    for (int i = 1; i <= nV; i++) {
        if (max[i] > 0 && max2[i] > 0) {
            ans = std::max(ans, 1LL + max[i] + max2[i] + 2 * (exp - 1) * h);
        }
    }
    printf("%lld", ans);
    return 0;
}