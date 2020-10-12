#include <stdio.h>
#include <vector>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &diff[i]);
    }
    int bestSum = 0; 
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        diff[i] -= value;
        bestSum += std::abs(diff[i]);
    }
    for (int C = -1000; C <= 1000; C++) {
        int curSum = 0;
        for (int i = 0; i < n; i++) {
            curSum += std::abs(diff[i] + C);
        }
        if (curSum < bestSum) {
            bestSum = curSum;
        }
    }
    printf("%d", bestSum);
    return 0;
}