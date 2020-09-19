#include <stdio.h>
#include <vector>
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
	int nV;
	scanf("%d", &nV);
	std::vector<int> cost(nV);
	for (int i = 0; i < nV; i++) {
		scanf("%d", &cost[i]);
	}
	int nE;
	scanf("%d", &nE);
	std::vector<std::vector<int>> e(nV);
	for (int i = 0; i < nE; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		from--;
		to--;
		e[from].push_back(to);
		e[to].push_back(from);
	}

	const int INF = 10000000;
	std::vector<bool> was(nV, false);
	std::vector<int> d(nV, INF);
	std::priority_queue<Vertex> q;
	d[0] = 0;
	q.push(Vertex{ 0, 0 });

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
		
		for (int i = 0; i < (int)e[min.v].size(); i++) {
			int to = e[min.v][i];
			int from = min.v;
			if (d[to] > d[from] + cost[from]) {
				d[to] = d[from] + cost[from];
				q.push(Vertex{ to, d[to]});
			}
		}
	}
	
	if (d[nV - 1] == INF) {
		printf("-1");
	} else {
		printf("%d", d[nV - 1]);
	}
	return 0;
}