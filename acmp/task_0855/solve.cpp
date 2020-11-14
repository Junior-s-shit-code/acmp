#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nTypes, nValues;
    scanf("%d %d", &nTypes, &nValues);
    std::vector <int> a(nValues);
    for (int i = 0; i < nValues; i++) {
        scanf("%d", &a[i]);
    }
    std::map <int, int> ansCount;
    std::map <int, int> curCount;
    int ansSize = 0;
    for (int i = 0; i + 1 < nValues; i++) {
        int val = a[i] / (a[i] - a[i + 1]);
        if (curCount[val] > 0) {
            curCount[val]--;
            curCount[val - 1]++;
        } else {
            ansCount[val]++;
            curCount[val - 1]++;
            ansSize++;
        }
    }
    int last = a.back();
    for (auto kv : curCount) {
        for (int i = 0; i < kv.second; i++) {
            last /= kv.first;
        }
    }
    if (last > 1) {
        ansCount[last]++;
        ansSize++;
    }
    while (ansSize < nTypes) {
        ansCount[1]++;
        ansSize++;
    }
    bool first = true;
    for (auto kv : ansCount) {
        for (int i = 0; i < kv.second; i++) {
            printf("%d ", kv.first);
        }
    }
    return 0;
}