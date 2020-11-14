#include <stdio.h>
#include <string>
#include <vector>

int main() {
    const int MOD = (int)1e9 + 9;
    char buf[1 + 100];
    scanf("%s", &buf);
    std::string s(buf);
    int n = (int)s.length();
    std::vector<std::vector<bool>> isPal(1 + n, std::vector<bool>(1 + n, false));
    for (int iLen = 1; iLen <= n; iLen++) {
        for (int iLeft = 1; iLeft + iLen - 1 <= n; iLeft++) {
            int iRight = iLeft + iLen - 1;
            if (iLen == 1) {
                isPal[iLeft][iRight] = true;
            } else if (iLen == 2) {
                isPal[iLeft][iRight] = s[iLeft - 1] == s[iRight - 1];
            } else {
                isPal[iLeft][iRight] = s[iLeft - 1] == s[iRight - 1] && isPal[iLeft + 1][iRight - 1];
            }
        }
    }
    std::vector<int> countPartitions(1 + n);
    countPartitions[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (isPal[j][i]) {
                countPartitions[i] = (countPartitions[i] + countPartitions[j - 1]) % MOD;
            }
        }
    }
    printf("%d", countPartitions[n]);
    return 0;
}