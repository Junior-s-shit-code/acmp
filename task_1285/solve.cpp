#include <stdio.h>
#include <vector>
#include <queue>

struct Point {

	int i;

	int j;
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int INF = (int)1e9;
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	std::vector<std::vector<char>> field(sizeI + 2, std::vector<char>(sizeJ + 2, '#'));
	Point start, end;
	for (int i = 1; i <= sizeI; i++) {
		for (int j = 1; j <= sizeJ; j++) {
			scanf(" %c", &field[i][j]);
			if (field[i][j] == 'S') {
				start = Point{ i, j };
			}
			if (field[i][j] == 'E') {
				end = Point{ i, j };
			}
		}
	}
	std::vector<std::vector<int>> len(sizeI + 2, std::vector<int>(sizeJ + 2, INF));
	len[start.i][start.j] = 0;

	std::queue<Point> q;
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
				if (field[newI][newJ] == 'B') {
					int k = 2;
					int bi = newI + di;
					int bj = newJ + dj;
					while (field[bi][bj] == 'B') {
						k++;
						bi += di;
						bj += dj;
					}
					if (field[bi][bj] == '#') {
						continue;
					} 
					if (len[bi][bj] > len[cur.i][cur.j] + k) {
						len[bi][bj] = len[cur.i][cur.j] + k;
						q.push(Point{ bi,bj });
					}

				} else if (field[newI][newJ] != '#' && len[newI][newJ] > len[cur.i][cur.j] + 1) {
					len[newI][newJ] = len[cur.i][cur.j] + 1;
					q.push(Point{ newI, newJ });
				}
			}
		}
	}
	if (len[end.i][end.j] == INF) {
		printf("-1");
	} else {
		printf("%d", len[end.i][end.j]);
	}

	return 0;
}