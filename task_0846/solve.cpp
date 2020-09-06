#include <stdio.h>
#include <vector>
#include <queue>

struct Point {

	int i;

	int j;

	static Point read() {
		int i, j;
		scanf("%d %d", &i, &j);
		return Point{ i, j };
	}
};

int run(const Point &start, const Point &end, const int extra, const int maxTime, const int sizeI, const int sizeJ, const std::vector <std::vector <bool>> &isFree) {
	std::queue <Point> q;
	q.push(start);
	const int INF = 1000000;
	std::vector <std::vector <int>> len(sizeI + 2, std::vector <int>(sizeJ + 2, INF));
	len[start.i][start.j] = 0;

	if (!isFree[start.i][start.j]) {
		return 0;
	}

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
				if (isFree[newI][newJ] && len[cur.i][cur.j] + 1 < len[newI][newJ]) {
					len[newI][newJ] = len[cur.i][cur.j] + 1;
					q.push(Point{ newI, newJ });
				}
			}
		}
	}

	return (len[end.i][end.j] <= maxTime ? extra : 0);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	std::vector <std::vector <bool>> isFree(sizeI + 2, std::vector <bool>(sizeJ + 2, false));
	for (int i = 1; i <= sizeI; i++) {
		for (int j = 1; j <= sizeJ; j++) {
			char c;
			scanf(" %c", &c);
			if (c == '0') {
				isFree[i][j] = true;
			}
		}
	}
	Point end = Point::read();
	int maxTime;
	scanf("%d", &maxTime);
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		Point start = Point::read();
		int extra;
		scanf("%d", &extra);
		int plus = run(start, end, extra, maxTime, sizeI, sizeJ, isFree);
		ans += plus;
	}
	printf("%d", ans);
	return 0;
}