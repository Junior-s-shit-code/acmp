#include <stdio.h>
#include <vector>
#include <queue>

const int INF = (int)1e9;

struct Point {

    int i;

    int j;
};

void bfs(
    const Point start,
    const int sizeI,
    const int sizeJ,
    const int nIterations,
    const std::vector<std::vector<int>> &a,
    int &sum,
    int &maxDist,
    std::vector<std::vector<int>> &dist
) {
    dist[start.i][start.j] = 1;
    std::queue<Point> q;
    q.push(start);
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di * di + dj * dj != 1) {
                    continue;
                }
                int newI = cur.i + di;
                int newJ = cur.j + dj;
                if (0 <= newI && newI < sizeI &&
                    0 <= newJ && newJ < sizeJ &&
                    dist[cur.i][cur.j] + 1 < dist[newI][newJ] &&
                    dist[cur.i][cur.j] + 1 <= nIterations
                ) {
                    if (dist[newI][newJ] == INF) {
                        sum += a[newI][newJ];
                    }
                    q.push(Point{ newI, newJ });
                    dist[newI][newJ] = dist[cur.i][cur.j] + 1;
                }
            }
        }
    }
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            if (dist[i][j] != INF) {
                maxDist = std::max(maxDist, dist[i][j]);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int sizeI, sizeJ, nIterations;
    scanf("%d %d %d", &sizeI, &sizeJ, &nIterations);
    std::vector<std::vector<int>> a(sizeI, std::vector<int>(sizeJ));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int bestSum = -INF;
    int bestI = 0;
    int bestJ = 0;
    int bestIteration = 0;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            for (int iIteration = 1; iIteration <= nIterations; iIteration++) {
                std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, INF));
                int sum = a[i][j];
                int maxIteration = 0;
                bfs(Point{i, j}, sizeI, sizeJ, iIteration, a, sum, maxIteration, dist);
                if (sum > bestSum) {
                    bestSum = sum;
                    bestIteration = maxIteration;
                    bestI = i;
                    bestJ = j;
                } else if (sum == bestSum &&
                    maxIteration < bestIteration
                ) {
                    bestIteration = maxIteration;
                    bestI = i;
                    bestJ = j;
                } else if (sum == bestSum &&
                    maxIteration == bestIteration &&
                    i < bestI
                ) {
                    bestI = i;
                    bestJ = j;
                } else if (sum == bestSum &&
                    maxIteration == bestIteration &&
                    i == bestI &&
                    j < bestJ
                ) {
                    j = bestJ;
                }
            }
        }
    }
    printf("%d %d %d %d", bestI + 1, bestJ + 1, bestIteration, bestSum);
    return 0;
}