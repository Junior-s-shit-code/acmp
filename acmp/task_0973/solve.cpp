#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <set>

const int INF = 2 * (int)1e9 + 1;

struct Edge {

	int to;
	
	int cost;

	int id;
};

struct Vertex {

	int v;

	int dist;

	bool operator<(const Vertex &second) const {
		if (dist != second.dist) {
			return dist > second.dist;
		}
		return v > second.v;
	}
};

void findBridges(
	int curV,
	int prevEdgeId,
	int &curTime,
	std::vector<int> &time,
	std::vector<int> &minTime,
	const std::vector<std::vector<Edge>> &g,
	std::set<int> &bridges
) {
	time[curV] = curTime;
	minTime[curV] = curTime;
	curTime++;
	for (const Edge &e : g[curV]) {
		int nextV = e.to;
		if (prevEdgeId == e.id) {
			continue;
		}
		if (time[nextV] == -1) {
			findBridges(nextV, e.id, curTime, time, minTime, g, bridges);
			if (time[curV] < minTime[nextV]) {
				bridges.insert(e.id);
			}
			minTime[curV] = std::min(minTime[curV], minTime[nextV]);
		} else {
			minTime[curV] = std::min(minTime[curV], time[nextV]);
		}
	}
}

void dijkstra(
	const int nV,
	std::vector<int> &d,
	const std::vector<std::vector<Edge>> &g
) {
	std::vector<bool> was(nV, false);
	d[0] = 0;
	std::priority_queue<Vertex> q;
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
		for (const Edge &e : g[min.v]) {
			if (d[e.to] > min.dist + e.cost) {
				d[e.to] = min.dist + e.cost;
				q.push(Vertex{ e.to, d[e.to] });
			}
		}
	}
}

void walkBackward(
	int curV,
	std::vector<bool> &visitedBackward,
	const std::vector<std::vector<Edge>> &backwardOptimalEdges
) {
	visitedBackward[curV] = true;
	for (const Edge &e : backwardOptimalEdges[curV]) {
		if (!visitedBackward[e.to]) {
			walkBackward(e.to, visitedBackward, backwardOptimalEdges);
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	std::vector<std::vector<Edge>> g(nV);
	for (int i = 0; i < nE; i++) {
		int v1, v2, cost;
		scanf("%d %d %d", &v1, &v2, &cost);
		v1--;
		v2--;
		g[v1].push_back(Edge{ v2, cost, i });
		g[v2].push_back(Edge{ v1, cost, i });
	}

	std::vector<int> d(nV, INF);
	dijkstra(nV, d, g);
	
	std::vector<bool> visitedBackward(nV, false);
	{
		std::vector<std::vector<Edge>> backwardOptimalEdges(nV);
		for (int v = 0; v < nV; v++) {
			for (const Edge &e : g[v]) {
				if (d[e.to] == d[v] + e.cost) {
					backwardOptimalEdges[e.to].push_back(Edge{ v, e.cost, e.id });
				}
			}
		}
		walkBackward(nV - 1, visitedBackward, backwardOptimalEdges);
	}

	
	std::set<int> ans;
	{
		std::vector<std::vector<Edge>> optimalEdges(nV);
		for (int v = 0; v < nV; v++) {
			if (!visitedBackward[v]) {
				continue;
			}
			for (const Edge &e : g[v]) {
				if (d[e.to] == d[v] + e.cost && visitedBackward[e.to]) {
					optimalEdges[v].push_back(Edge{ e.to, e.cost, e.id });
					optimalEdges[e.to].push_back(Edge{ v, e.cost, e.id });
				}
			}
		}
		int curTime = 0;
		std::vector<int> time(nV, -1);
		std::vector<int> minTime(nV, -1);
		findBridges(0, -1, curTime, time, minTime, optimalEdges, ans);
	}
	
	printf("%d\n", (int)ans.size());
	for (int item : ans) {
		printf("%d ", item + 1);
	}
	return 0;
}