#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            totalSum += a[i][j];
        }
    }

    int nPermutations = 1;
    std::vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[i] = i;
        nPermutations *= (i + 1);
    }
    int minSum = INT_MAX;
    std::vector<int> ans;
    
    do {
        int staySum = 0;
        for (int i = 0; i < n; i++) {
            staySum += a[i][pos[i]];
        }
        int curSum = totalSum - staySum;
        if (curSum < minSum) {
            minSum = curSum;
            ans = pos;
        }
    } while (std::next_permutation(pos.begin(), pos.end()));

    for (int i = 0; i < n; i++) {
        printf("%c", 'A' + ans[i]);
    }
    printf("\n%d", minSum);
    return 0;
}