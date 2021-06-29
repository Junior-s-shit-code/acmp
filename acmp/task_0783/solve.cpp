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
    const int SIZE = 8;
    const char WALL = '#';
    const int UNDEF = -1;
    const int CHECKED = 0;
    std::vector<std::vector<char>> a(1 + SIZE + 1, std::vector<char>(1 + SIZE + 1, WALL));
    std::vector<std::vector<int>> color(1 + SIZE + 1, std::vector<int>(1 + SIZE + 1, UNDEF));
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    int newColor = 1;
    std::queue<Pos> newSquare;
    newSquare.push(Pos{ 1, 1 });
    color[1][1] = CHECKED;
    while (!newSquare.empty()) {
        Pos start = newSquare.front();
        newSquare.pop();
        if (color[start.i][start.j] != CHECKED) {
             continue;
        }
        std::queue<Pos> q;
        q.push(start);
        while (!q.empty()) {
            Pos cur = q.front();
            q.pop();
            if (color[cur.i][cur.j] != CHECKED) {
                continue;
            }
            color[cur.i][cur.j] = newColor;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di * di + dj * dj != 1) {
                        continue;
                    }
                    int newI = cur.i + di;
                    int newJ = cur.j + dj;
                    if (a[cur.i][cur.j] != a[newI][newJ] &&
                        a[newI][newJ] != WALL &&
                        (color[newI][newJ] == UNDEF ||
                         color[newI][newJ] == CHECKED)
                    ) {
                        q.push(Pos{ newI, newJ });
                        color[newI][newJ] = CHECKED;
                    } else if (a[cur.i][cur.j] == a[newI][newJ] && 
                               color[newI][newJ] == UNDEF
                    ) {
                        newSquare.push(Pos{ newI, newJ });
                        color[newI][newJ] = CHECKED;
                    }
                }
            }
        }
        newColor++;
    }
    printf("%d", newColor - 1);
    return 0;
}