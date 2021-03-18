#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
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

    for (int iPermutation = 0; iPermutation < nPermutations; iPermutation++) {
        int curSum = 0;
        for (int i = 0; i < n; i++) {
            int stay = pos[i];
            for (int j = 0; j < n; j++) {
                if (j != stay) {
                    curSum += a[i][j];
                }
            }
        }
        if (curSum < minSum) {
            minSum = curSum;
            ans = pos;
        }
        std::next_permutation(pos.begin(), pos.end());
    }
    for (int i = 0; i < n; i++) {
        printf("%c", 'A' + ans[i]);
    }
    printf("\n%d", minSum);
    return 0;
}