#include <stdio.h>
#include <vector>
#include <queue>

struct Pos {

    int i;

    int j;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int INF = 30 * 30 * 100 + 1;
    const int WALL = -1;
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<int>> a(1 + sizeI + 1, std::vector<int>(1 + sizeJ + 1, INF));
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    std::vector<std::vector<int>> count(1 + sizeI + 1, std::vector<int>(1 + sizeJ + 1, INF));
    count[1][1] = a[1][1];
    std::queue<Pos> q;
    q.push(Pos{ 1, 1 });

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di * di + dj * dj != 1) {
                    continue;
                }

                int newI = cur.i + di;
                int newJ = cur.j + dj;
                
                if (count[cur.i][cur.j] + a[newI][newJ] < count[newI][newJ]) {
                    count[newI][newJ] = count[cur.i][cur.j] + a[newI][newJ];
                    q.push(Pos{ newI, newJ });
                }
            }
        }
    }
    printf("%d", count[sizeI][sizeJ]);
    return 0;
}