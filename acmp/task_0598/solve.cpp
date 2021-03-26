#include <stdio.h>
#include <vector>

bool check(int iComb, const std::vector<std::vector<bool>> &friends) {
    std::vector<int> group;
    int id = 0;
    while (iComb > 0) {
        if ((iComb & 1) == 1) {
            group.push_back(id);
        }
        iComb >>= 1;
        id++;
    }
    for (int iSecond = 0; iSecond < (int)group.size(); iSecond++) {
        for (int iFirst = 0; iFirst < iSecond; iFirst++) {
            if (!friends[group[iFirst]][group[iSecond]]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MAX_GROUP = 5;
    int n;
    scanf("%d", &n);
    std::vector<std::vector<bool>> friends(n, std::vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            friends[i][j] = (val == 1);
        }
    }

    int bestGroupSize = 0;
    int bestComb = -1;
    for (int iComb = 0; iComb < (1 << n); iComb++) {
        int curGroupSize = __builtin_popcount(iComb);
        if (curGroupSize <= MAX_GROUP &&
            curGroupSize > bestGroupSize &&
            check(iComb, friends)
        ) {
            bestComb = iComb;
            bestGroupSize = curGroupSize;
        }
    }

    printf("%d\n", n - bestGroupSize + 1);
    int id = 2;
    for (int i = 0; i < n; i++) {
        if ((bestComb & 1) == 1) {
            printf("%d ", 1);
        } else {
            printf("%d ", id);
            id++;
        }
        bestComb >>= 1;
    }

    return 0;
}