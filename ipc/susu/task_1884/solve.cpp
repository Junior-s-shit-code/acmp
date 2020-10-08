#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

struct Point {
    
    int i;

    int j;
    
    static Point read() {
        int i, j;
        scanf("%d %d", &i, &j);
        return Point{ i, j };
    }
};

int bfs(const int startI, const int startJ, const int sizeI, const int sizeJ, const std::vector<std::vector<int>> &a) {
    const int INF = (int)1e9;
    const int WALL = -1;
    const int WAY = 0;
    std::vector<std::vector<int>> len(sizeI + 2, std::vector<int>(sizeJ + 2, INF));
    std::queue<Point> q;
    q.push(Point{ startI, startJ });
    len[startI][startJ] = 0;
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
                if (a[newI][newJ] != WALL && len[newI][newJ] > len[cur.i][cur.j] + 1) {
                    len[newI][newJ] = len[cur.i][cur.j] + 1;
                    if (a[newI][newJ] == WAY) {
                        q.push(Point{ newI, newJ });
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            if (a[i][j] > 0) {
                ans += std::max(0, a[i][j] - len[i][j] + 1);
            }
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<int>> field(sizeI + 2, std::vector<int>(sizeJ + 2, -1));
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            scanf("%d", &field[i][j]);
        }
    }
    int bestSum = -1;
    int ansI;
    int ansJ;
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            if (field[i][j] == 0) {
                int value = bfs(i, j, sizeI, sizeJ, field);
                if (value > bestSum) {
                    bestSum = value;
                    ansI = i;
                    ansJ = j;
                }
            }
        }
    }
    printf("%d\n%d %d", bestSum, ansI, ansJ);
    return 0;
}