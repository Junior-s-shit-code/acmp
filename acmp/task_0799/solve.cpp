#include <stdio.h>
#include <algorithm>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    int winScore = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        winScore = std::max(winScore, a[i]);
    }
    bool wasWinShot = false;
    int maxAns = -1;
    for (int i = 0; i + 1 < n; i++) {
        if (wasWinShot &&
            a[i] % 10 == 5 &&
            a[i] > a[i + 1]
        ) {
            maxAns = std::max(maxAns, a[i]);
        }
        if (a[i] == winScore) {
            wasWinShot = true;
        }
    }
    std::sort(a.begin(), a.end(), [](const int &left, const int &right) {
        return left > right;
    });
    for (int i = 0; i < n; i++) {
        if (maxAns == a[i]) {
            printf("%d", i + 1);
            return 0;
        }
    }
    printf("0");
    return 0;
}