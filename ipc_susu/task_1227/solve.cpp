#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <set>

struct Pair {

    int i;
    
    int j;

    bool operator <(const Pair &second) const{
        if (i == second.i) {
            return j < second.j;
        }
        return i < second.i;
    }

    bool operator ==(const Pair &second) const{
        return i == second.i && j == second.j;
    }
};

bool isFullShip(
    const int startI,
    const int startJ,
    const std::vector<std::vector<bool>> &ship,
    const std::vector<std::vector<bool>> &damaged
) {
    std::set<Pair> checkedShip;
    std::queue<Pair> q;
    q.push(Pair{ startI, startJ });
    int totalSells = 0;
    int damagedSells = 0;
    while (!q.empty()) {
        Pair cur = q.front();
        q.pop();
        checkedShip.insert(cur);
        totalSells++;
        if (damaged[cur.i][cur.j]) {
            damagedSells++;
        }
        if (totalSells != damagedSells) {
            return false;
        }
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di * di + dj * dj != 1) {
                    continue;
                }
                int newI = cur.i + di;
                int newJ = cur.j + dj;
                if (0 <= newI && newI < 10 &&
                    0 <= newJ && newJ < 10 &&
                    ship[newI][newJ] &&
                    checkedShip.find(Pair{ newI, newJ }) == checkedShip.end()
                ) {
                    q.push(Pair{ newI, newJ });
                }
            }
        }
    }
    return true;
}

std::string ask(
    const int i,
    const int j,
    std::vector<std::vector<bool>> &was,
    std::vector<std::vector<bool>> &damaged,
    const std::vector<std::vector<bool>> &ship)
{
    if (was[i][j]) {
        return std::string("repeated");
    }
    was[i][j] = true;
    if (ship[i][j] == false) {
        return std::string("missed");
    }
    damaged[i][j] = true; 
    if (isFullShip(i, j, ship, damaged)) {
        return std::string("sinked");
    } else {
        return std::string("damaged");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int SIZE = 10;
    int nQ;
    scanf("%d", &nQ);
    std::vector<std::vector<bool>> ship(SIZE, std::vector<bool>(SIZE, false));
    std::vector<std::vector<bool>> was(SIZE, std::vector<bool>(SIZE, false));
    std::vector<std::vector<bool>> damaged(SIZE, std::vector<bool>(SIZE, false));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char val;
            scanf(" %c", &val);
            ship[i][j] = (val == '#');
        }
    }
    for (int q = 0; q < nQ; q++) {
        int val;
        scanf("%d", &val);
        val--;
        int shotI = val / 10;
        int shotJ = val % 10;
        printf("%s\n", ask(shotI, shotJ, was, damaged, ship).c_str());
    }
    return 0;
}