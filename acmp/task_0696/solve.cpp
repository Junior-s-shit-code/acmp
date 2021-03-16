#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

const int N_KEYS = 4;
const int N_COMBINATIONS = 1 << N_KEYS;
const char WALL = 'X';
const char FREE = '.';
const char VISITED = '*';
const std::vector<char> keys{ 'R', 'G', 'B', 'Y' };

struct Pos {

    int i;

    int j;
};

void updateMap(
    const char key,
    const int sizeI,
    const int sizeJ,
    std::vector<std::vector<char>> &map
) {
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            if (map[i][j] == key) {
                map[i][j] = FREE;
            }
        }
    }
}

void dfs(
    Pos cur,
    std::vector<std::vector<char>> &map
) {
    map[cur.i][cur.j] = VISITED;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di * di + dj * dj == 1) {
                int newI = cur.i + di;
                int newJ = cur.j + dj;
                if (map[newI][newJ] == FREE) {
                    dfs(Pos{ newI, newJ }, map);
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int INF = N_KEYS * 100 + 1;
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<int> cost(N_KEYS);
    for (int iKey = 0; iKey < N_KEYS; iKey++) {
        scanf("%d", &cost[iKey]);
    }
    Pos start, end;
    std::vector<std::vector<char>> a(1 + sizeI + 1, std::vector<char>(1 + sizeJ + 1, WALL));
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'S') {
                start = Pos{ i, j };
                a[i][j] = FREE;
            } else if (a[i][j] == 'E') {
                end = Pos{ i, j };
                a[i][j] = FREE;
            } 
        }
    }
    std::vector<std::vector<char>> map;
    int minCost = INF;
    for (int code = 0; code < N_COMBINATIONS; code++) {
        map = a;
        int curCost = 0;
        for (int iKey = 0; iKey < N_KEYS; iKey++) {
            if (((code >> iKey) & 1) != 0) {
                curCost += cost[iKey];
                updateMap(keys[iKey], sizeI, sizeJ, map);
            }
        }
        dfs(start, map);
        if (map[end.i][end.j] == VISITED) {
            minCost = std::min(minCost, curCost);
        }
    }

    if (minCost == INF) {
        printf("Sleep");
    } else {
        printf("%d", minCost);
    }
    return 0;
}