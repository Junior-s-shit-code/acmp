#include <stdio.h>
#include <vector>

struct Edge {

    int to;

    int timeStart;

    int timeEnd;
};

void dfs(
    int curV,
    int time,
    const int endV,
    std::vector<int> &minTime,
    const std::vector<std::vector<Edge>> &g
) {
    minTime[curV] = time;
    if (curV != endV) {
        for (const Edge &e : g[curV]) {
            if (time <= e.timeStart && e.timeEnd < minTime[e.to]) {
                dfs(e.to, e.timeEnd, endV, minTime, g);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int INF = (int)1e9 + 7;
    int nV, end, nE;
    scanf("%d %d %d", &nV, &end, &nE);
    std::vector<std::vector<Edge>> g(nV + 1);
    for (int i = 0; i < nE; i++) {
        int n;
        scanf("%d", &n);
        int prevV, timeStart;
        for (int i = 0; i < n; i++) {
            int v, timeEnd;
            scanf("%d %d", &v, &timeEnd);
            if (i > 0) {
                g[prevV].push_back(Edge{ v, timeStart, timeEnd });
            }
            prevV = v;
            timeStart = timeEnd;
        }
    }
    std::vector<int> minTime(nV + 1, INF);
    dfs(1, 0, end, minTime, g);
    printf("%d", minTime[end] == INF ? -1 : minTime[end]);
    return 0;
}