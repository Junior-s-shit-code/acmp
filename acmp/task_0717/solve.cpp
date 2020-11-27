#include <stdio.h>
#include <vector>

void dfs(
    int curV,
    long long &allTime,
    std::vector<bool> &was,
    std::vector<int> &ans,
    const std::vector<int> &time,
    const std::vector<std::vector<int>> &g
) {
    was[curV] = true;
    allTime += time[curV];
    for (int nextV : g[curV]) {
        if (nextV > 0 && !was[nextV]) {
            dfs(nextV, allTime, was, ans, time, g);
        }
    }
    ans.push_back(curV);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nV;
    scanf("%d", &nV);
    std::vector<int> time(nV);
    for (int v = 0; v < nV; v++) {
        scanf("%d", &time[v]);
    }
    std::vector<std::vector<int>> beforeCrafted(nV);
    for (int v = 0; v < nV; v++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int value;
            scanf("%d", &value);
            beforeCrafted[v].push_back(value - 1);
        }
    }
    long long allTime = 0;
    std::vector<bool> was(nV, false);
    std::vector<int> ans;
    dfs(0, allTime, was, ans, time, beforeCrafted);
    printf("%lld %d\n", allTime, (int)ans.size());
    for (int item : ans) {
        printf("%d ", item + 1);
    }
    return 0;
}