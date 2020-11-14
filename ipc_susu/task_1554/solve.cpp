#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

void findCutPoints(
    int curV,
    int prevV, 
    int &curTime,
    std::vector<int> &time,
    std::vector<int> &minTime,
    const std::vector<std::vector<int>> &g, 
    std::set<int> &cutPoints
) {
    time[curV] = curTime;
    minTime[curV] = curTime;
    curTime++;
    int childCount = 0;
    for (int nextV : g[curV]) {
        if (nextV == prevV) {
            continue;
        }
        if (time[nextV] == -1) {
            findCutPoints(nextV, curV, curTime, time, minTime, g, cutPoints);
            childCount++;
            if (prevV != -1 && minTime[nextV] >= time[curV] ||
                prevV == -1 && childCount > 1
            ) {
                cutPoints.insert(curV);
            }
            minTime[curV] = std::min(minTime[curV], minTime[nextV]);
        } else {
            minTime[curV] = std::min(minTime[curV], time[nextV]);
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

    std::vector<int> time(nV, -1);
    std::vector<int> minTime(nV, -1);
    std::set<int> ans;
    int curTime = 0;
    findCutPoints(0, -1, curTime, time, minTime, g, ans);
    printf("%d\n", (int)ans.size());
    for (int item : ans) {
        printf("%d ", item + 1);
    }
    return 0;
}