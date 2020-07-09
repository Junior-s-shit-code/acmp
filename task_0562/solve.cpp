#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

struct Vertex {

	int v;

	int dist;

	bool operator <(const Vertex &second) const {
		if (dist != second.dist) {
			return dist > second.dist;
		}
		return v > second.v;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	const int INF = 100000;
	std::vector <std::vector <int>> edges(n, std::vector <int>(n, INF));
	for (int i = 0; i < n; i++) {
		edges[i][i] = 0;
	}
	for (int i = 0; i < k; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		v1--;
		v2--;
		edges[v1][v2] = 0;
		edges[v2][v1] = std::min(edges[v2][v1], 1);
	}

	int ans = 0;
	for (int from = 0; from < n; from++) {
		std::vector <int> d(n, INF);
		d[from] = 0;
		std::vector <bool> was(n, false);
		std::priority_queue <Vertex> q;
		q.push(Vertex { from, d[from] });

		while (!q.empty()) {
			Vertex min = q.top();
			q.pop();

			if (was[min.v]) {
				continue;
			}

			if (min.dist == INF) {
				break;
			}

			was[min.v] = true;
			for (int to = 0; to < n; to++) {
				int cost = edges[min.v][to];
				if (min.dist + cost < d[to]) {
					d[to] = min.dist + cost;
					q.push(Vertex { to, d[to] });
				}
			}
		}
		for (int i = 0; i < n; i++) {
			ans = std::max(ans, d[i]);
		}
	}
	printf("%d", ans);
	return 0;
}