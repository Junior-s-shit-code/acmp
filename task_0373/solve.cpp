#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

struct Point {

    int i;

    int j;
};


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, maxK;
    scanf("%d %d", &n, &maxK);
    std::vector <std::vector <int>> a(n, std::vector <int>(n));
    std::vector <std::vector <long long>> curStep(n, std::vector <long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    curStep[0][0] = a[0][0];
    for (int k = 1; k < maxK; k++) {
        std::vector <std::vector <long long>> nextStep(n, std::vector <long long>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (curStep[i][j] == 0) {
                    continue;
                }
                //algo
                if (i + 1 < n) {
                    nextStep[i + 1][j] = std::max(nextStep[i + 1][j], curStep[i][j] + a[i + 1][j]);
                }
                if (i - 1 >= 0) {
                    nextStep[i - 1][j] = std::max(nextStep[i - 1][j], curStep[i][j] + a[i - 1][j]);
                }
                if (j + 1 < n) {
                    nextStep[i][j + 1] = std::max(nextStep[i][j + 1], curStep[i][j] + a[i][j + 1]);
                }
                if (j - 1 >= 0) {
                    nextStep[i][j - 1] = std::max(nextStep[i][j - 1], curStep[i][j] + a[i][j - 1]);
                }
            }
        }
        curStep = nextStep;
    }

    long long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max = std::max(max, curStep[i][j]);
        }
    }
    printf("%lld", max);
    return 0;
}