#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

struct Edge {

	int to;

	int id;
};

void findBridges(int curV,
				 int prevV,
				 int &curTime,
				 std::vector<int> &time,
				 std::vector<int> &minTime,
				 std::vector<std::vector<Edge>> &g,
				 std::set<int> &bridges
) {
	time[curV] = curTime;
	minTime[curV] = curTime;
	curTime++;
	for (Edge &e : g[curV]) {
		int nextV = e.to;
		if (nextV == prevV) {
			continue;
		}
		if (time[nextV] == -1) {
			findBridges(nextV, curV, curTime, time, minTime, g, bridges);
			minTime[curV] = std::min(minTime[curV], time[nextV]);
			if (time[curV] < minTime[nextV]) {
				bridges.insert(e.id);
			}
			minTime[curV] = std::min(minTime[curV], minTime[nextV]);
		} else {
			minTime[curV] = std::min(minTime[curV], time[nextV]);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	std::vector<std::vector<Edge>> g(nV);
	for (int iE = 0; iE < nE; iE++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		v1--;
		v2--;
		g[v1].push_back(Edge{ v2, iE + 1});
		g[v2].push_back(Edge{ v1, iE + 1});
	}

	int curTime = 0;
	std::set<int> ans;
	std::vector<int> time(nV, -1);
	std::vector<int> minTime(nV, -1);

	findBridges(0, -1, curTime, time, minTime, g, ans);
	printf("%d\n", (int)ans.size());
	for (int item : ans) {
		printf("%d ", item);
	}
	return 0;
}