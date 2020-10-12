#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MULT = (int)1e4;
    int n, maxDist;
    scanf("%d %d", &n, &maxDist);
    maxDist *= MULT;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] *= MULT;
    }
    std::sort(a.begin(), a.end());
    int bestAns = (int)1e9;
    for (int startD = 1; startD <= 1000; startD++) {
        int curDivisor = startD;
        int curAns = curDivisor;
        int minValue = a[0] / startD;
        bool isGoNext;
        for (int i = 1; i < n; i++) {
            isGoNext = false;
            while (true) {
                int seg = a[i] / curDivisor;
                int diff = std::abs(seg - minValue);
                if (diff <= maxDist) {
                    isGoNext = true;
                    curAns += curDivisor;
                    if (seg < minValue) {
                        minValue = seg;
                    }
                    break;
                } else if (seg < minValue) {
                    break;
                }
                curDivisor++;
                if (curDivisor > 1000) {
                    break;
                }
            }
            if (!isGoNext) {
                break;
            }
        }
        if (isGoNext) {
            bestAns = curAns;
            break;
        }
    }
    printf("%d", bestAns - n);
    return 0;
}