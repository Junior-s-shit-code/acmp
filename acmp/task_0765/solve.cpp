#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

const char BLACK = 'B';
const char WHITE = 'W';
const char FREE = '.';

struct Pos {

    int i;

    int j;

    bool operator <(const Pos &second) const {
        if (i != second.i) {
            return i < second.i;
        }
        return j < second.j;
    }
};

bool inAtari(
    const Pos start,
    const std::vector<std::vector<char>> &a,
    std::vector<std::vector<bool>> &was
) {
    std::set<Pos> freeCells;
    std::queue<Pos> q;
    q.push(start);
    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        was[cur.i][cur.j] = true;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di * di + dj * dj != 1) {
                    continue;
                }
                int newI = cur.i + di;
                int newJ = cur.j + dj;

                if (a[newI][newJ] == FREE) {
                    freeCells.insert(Pos{ newI, newJ });
                } else if (a[newI][newJ] == BLACK && !was[newI][newJ]) {
                    q.push(Pos{ newI, newJ });
                }
            }
        }
    }
    return (int) freeCells.size() == 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<std::vector<char>> a(1 + n + 1, std::vector<char>(1 + n + 1, WHITE));
    std::vector<std::vector<bool>> was(1 + n + 1, std::vector<bool>(1 + n + 1, true));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %c", &a[i][j]);
            was[i][j] = false;
        }
    }
    int counter = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == BLACK && 
                !was[i][j] &&
                inAtari(Pos{ i, j }, a, was)
            ) {
                counter++;
            }
        }
    }
    printf("%d", counter);
    return 0;
}