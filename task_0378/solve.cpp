#include <stdio.h>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int SIZE = 500 * 100 + 1;
    int n;
    scanf("%d", &n);
    std::vector <bool> curStep(SIZE, false);
    curStep[0] = true;
    std::vector <bool> nextStep = curStep;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int extraValue;
        scanf("%d", &extraValue);
        for (int j = 0; j < SIZE; j++) {
            if (curStep[j]) {
                if (!nextStep[j + extraValue]) {
                    ans++;
                }
                nextStep[j + extraValue] = true;
            }
        }
        curStep = nextStep;
    }
    printf("%d", ans);
    return 0;
}