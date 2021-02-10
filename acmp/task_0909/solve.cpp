#include <stdio.h>
#include <vector>
#include <queue>

const char FREE = '-';
const char SHIP = 'S';
const char DAMAGED_SHIP = 'X';

struct Point {

    int i;

    int j;
};


void bfs(
    int i,
    int j,
    const int sizeI,
    const int sizeJ,
    bool &isDestroyed,
    bool &isAlive,
    bool &isDamaged,
    std::vector<std::vector<char>> &map
) {
    std::queue<Point> queue;
    queue.push(Point{ i, j });
    while (!queue.empty()) {
        Point cur = queue.front();
        queue.pop();
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di * di + dj * dj != 1) {
                    continue;
                }
                int newI = cur.i + di;
                int newJ = cur.j + dj;
                if (map[newI][newJ] != FREE) {
                    queue.push(Point{ newI, newJ });
                    if (isDestroyed && map[newI][newJ] == SHIP ||
                        isAlive && map[newI][newJ] == DAMAGED_SHIP
                    ) {
                        isDamaged = true;
                    }
                    map[newI][newJ] = FREE;
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
    std::vector<std::vector<char>> field(1 + sizeI + 1, std::vector<char>(1 + sizeJ + 1, FREE));
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            scanf(" %c", &field[i][j]);
        }
    }
    int countDestroyed = 0;
    int countDamaged = 0;
    int countAlive = 0;
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            bool isDestroyed = false;
            bool isAlive = false;
            bool isDamaged = false;

            if (field[i][j] == SHIP) {
                isAlive = true;
                bfs(i, j, sizeI, sizeJ, isDestroyed, isAlive, isDamaged, field);
            } else if (field[i][j] == DAMAGED_SHIP) {
                isDestroyed = true;
                bfs(i, j, sizeI, sizeJ, isDestroyed, isAlive, isDamaged, field);
            }

            if (isDamaged) {
                countDamaged++;
            } else if (isDestroyed) {
                countDestroyed++;
            } else if (isAlive) {
                countAlive++;
            }
        }
    }
    printf("%d %d %d", countAlive, countDamaged, countDestroyed);
    return 0;
}