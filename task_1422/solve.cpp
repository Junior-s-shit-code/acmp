#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <queue>

struct Point {

    int i;

    int j;

    bool operator==(Point &second) {
        return (i == second.i && j == second.j);
    }
};

Point getNextPoint(int i, int j, const short type) {
    if (type == 1) {
        j++;
    } else if (type == 2) {
        i--;
    } else if (type == 3) {
        j--;
    } else if (type == 4) {
        i++;
    }
    return Point{ i, j };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const short INF = SHRT_MAX;
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<short>> field(sizeI + 2, std::vector<short>(sizeJ + 2, INF));
    std::queue<Point> q;
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            short type;
            scanf("%hd", &type);
            field[i][j] = type;
            if ((i == 1 && type == 2) ||
                (j == 1 && type == 3) ||
                (i == sizeI && type == 4) ||
                (j == sizeJ && type == 1)
                ) {
                q.push(Point{ i, j });
            }

        }
    }
    int ans = sizeI * sizeJ;
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        ans--;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di * di + dj * dj != 1) {
                    continue;
                }
                int newI = cur.i + di;
                int newJ = cur.j + dj;
                if (getNextPoint(newI, newJ, field[newI][newJ]) == cur) {
                    q.push(Point{ newI, newJ });
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}