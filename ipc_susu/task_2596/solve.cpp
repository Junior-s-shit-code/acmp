#include <stdio.h>
#include <map>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, nSkip;
    scanf("%d %d", &n, &nSkip);
    std::map<int, int> prevIndex;
    std::map<int, int> count; 
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (prevIndex.find(val) == prevIndex.end() || 
            i - prevIndex[val] > nSkip
        ) {
            count[val]++;
            prevIndex[val] = i;
        }
    }
    int val;
    int maxCount = 0;
    for (auto item : count) {
        if (item.second > maxCount) {
            maxCount = item.second;
            val = item.first;
        }
    }
    printf("%d %d", val, maxCount);
    return 0;
}