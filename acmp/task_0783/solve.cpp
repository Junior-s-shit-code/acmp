#include <stdio.h>
#include <vector>
#include <set>

const char UNDEF = '#';
const int WALL = -1;
const int FREE = 0;
const int SIZE = 8;


int countColors(const std::vector<std::vector<int>> &color) {
    std::set<int> s;
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            s.insert(color[i][j]);
        }
    }
    return (int)s.size();
}


void rePaint(
    const int i,
    const int j,
    const int oldId,
    const int newId,
    std::vector<std::vector<int>> &color
) {
    color[i][j] = newId;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di * di + dj * dj != 1) {
                continue;
            }
            int newI = i + di;
            int newJ = j + dj;
            if (color[newI][newJ] == oldId) {
                rePaint(newI, newJ, oldId, newId, color);
            }
        }
    }
}

void dfs(
    const int i,
    const int j,
    int &id,
    std::vector<std::vector<char>> &a,
    std::vector<std::vector<int>> &color
) {
    color[i][j] = id;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di * di + dj * dj != 1) {
                continue;
            }
            int newI = i + di;
            int newJ = j + dj;

            if (color[newI][newJ] == WALL) {
                continue;
            }

            if (color[newI][newJ] == FREE) {
                if (a[i][j] != a[newI][newJ]) {
                    dfs(newI, newJ, id, a, color);
                } else {
                    id++;
                    dfs(newI, newJ, id, a, color);
                }
            } else if (color[i][j] != color[newI][newJ] &&
                       a[i][j] != a[newI][newJ]
            ) {
                rePaint(i, j, color[i][j], color[newI][newJ], color);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::vector<std::vector<char>> a(1 + SIZE + 1, std::vector<char>(1 + SIZE + 1, UNDEF));
    std::vector<std::vector<int>> color(1 + SIZE + 1, std::vector<int>(1 + SIZE + 1, WALL));
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            scanf(" %c", &a[i][j]);
            color[i][j] = FREE;
        }
    }

    int id = 1;
    dfs(1, 1, id, a, color);
    printf("%d", countColors(color));
    return 0;
}