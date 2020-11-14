#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

const int INF = (int)1e8;

void findCutPoints(
    int v,
    int prevV, 
    int &curTime,
    std::vector<int> &time,
    std::vector<int> &minTime,
    const std::vector<std::vector<int>> &g, 
    std::set<int> &ans
) {
    time[v] = curTime;
    minTime[v] = curTime;
    curTime++;
    int childCount = 0;
    for (int next : g[v]) {
        if (next == prevV) {
            continue;
        }
        if (time[next] != INF) {
            minTime[v] = std::min(minTime[v], minTime[next]);
        } else {
            findCutPoints(next, v, curTime, time, minTime, g, ans);
            minTime[v] = std::min(minTime[v], minTime[next]);
            childCount++;
            if (prevV < 0 && childCount > 1 ||
                prevV >= 0 && minTime[next] >= time[v]) {
                ans.insert(v);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<int>> g(nV);
    for (int iE = 0; iE < nE; iE++) {
        int from, to;
        scanf("%d %d", &from, &to);
        from--;
        to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    std::vector<int> time(nV, INF);
    std::vector<int> minTime(nV, INF);
    std::set<int> ans;
    int curTime = 0;
    findCutPoints(0, -1, curTime, time, minTime, g, ans);
    printf("%d\n", (int)ans.size());
    for (int item : ans) {
        printf("%d ", item + 1);
    }
    return 0;
}