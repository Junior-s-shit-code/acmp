#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

struct Point {

    int i;

    int j;
};

inline void check(const int di, const int dj, const int curI, const int curJ, const std::vector <std::vector <bool>>& field,
                  std::queue <Point> &q, std::vector <std::vector <int>>& len) {
    const int newI = curI + di;
    const int newJ = curJ + dj;
    if (field[newI][newJ] && len[newI][newJ] > len[curI][curJ] + 1) {
        len[newI][newJ] = len[curI][curJ] + 1;
        q.push(Point{ newI, newJ });
    }
}

void solve(const Point &start, const std::vector <std::vector <bool>>& field, std::vector <std::vector <int>>& len) {
    std::queue <Point> q;
    q.push(start);
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        check(1, 0, cur.i, cur.j, field, q, len);
        check(-1, 0, cur.i, cur.j, field, q, len);
        check(0, 1, cur.i, cur.j, field, q, len);
        check(0, -1, cur.i, cur.j, field, q, len);
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
    const int INF = 1000000000;
    std::vector <std::vector <int>> lenTiger(sizeI + 2, std::vector <int>(sizeJ + 2, INF));
    lenTiger[tiger.i][tiger.j] = 0;
    solve(tiger, field, lenTiger);
    std::vector <std::vector <int>> len(sizeI + 2, std::vector <int>(sizeJ + 2, INF));
    len[2][2] = 0;
    solve(Point{ 2, 2 }, field, len);
    printf("%d\n", len[sizeI - 1][sizeJ - 1]);
    if (len[sizeI - 1][sizeJ - 1] < lenTiger[sizeI - 1][sizeJ - 1]) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}