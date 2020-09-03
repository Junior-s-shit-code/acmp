#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

struct Point {

    int i;

    int j;
};

void bfs(const Point &start, const std::vector <std::vector <bool>> &field, std::vector <std::vector <int>> &len) {
    std::queue <Point> q;
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
                if (field[newI][newJ] && len[newI][newJ] > len[cur.i][cur.j] + 1) {
                    len[newI][newJ] = len[cur.i][cur.j] + 1;
                    q.push(Point{ newI, newJ });
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector <std::vector <bool>> field(sizeI + 2, std::vector <bool>(sizeJ + 2, false));
    Point tiger;
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            char c;
            scanf(" %c", &c);
            if (c == 'T') {
                tiger = Point{ i, j };
            } else if (c == '.') {
                field[i][j] = true;
            }
        }
    }
    const int INF = (int)1e9;
    std::vector <std::vector <int>> lenTiger(sizeI + 2, std::vector <int>(sizeJ + 2, INF));
    lenTiger[tiger.i][tiger.j] = 0;
    bfs(tiger, field, lenTiger);
    std::vector <std::vector <int>> len(sizeI + 2, std::vector <int>(sizeJ + 2, INF));
    Point slave = Point{ 2, 2 };
    len[slave.i][slave.j] = 0;
    bfs(slave, field, len);
    printf("%d\n", len[sizeI - 1][sizeJ - 1]);
    if (len[sizeI - 1][sizeJ - 1] < lenTiger[sizeI - 1][sizeJ - 1]) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}