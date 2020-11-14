#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nCursor;
    scanf("%d", &nCursor);
    std::vector<bool> cursor(nCursor);
    for (int i = 0; i < nCursor; i++) {
        int value;
        scanf("%d", &value);
        cursor[i] = value;
    }
    int nNumbers;
    scanf("%d", &nNumbers);
    std::vector<int> numbers(nNumbers);
    for (int i = 0; i < nNumbers; i++) {
        scanf("%d", &numbers[i]);
    }
    int bestSum = -1;
    std::vector<int> ans;
    for (int i = 0; i + nCursor <= nNumbers; i++) {
        int curSum = 0;
        std::vector<int> curNums;
        for (int j = 0; j < nCursor; j++) {
            if (cursor[j]) {
                curSum += numbers[i + j];
                curNums.push_back(numbers[i + j]);
            }
        }
        if (curSum > bestSum) {
            ans = curNums;
            bestSum = curSum;
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}