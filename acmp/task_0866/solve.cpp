#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_set>

void findCutPoints(
	int curV, 
	int prevV,
	int &curTime,
	const std::vector<std::vector<int>> &g,
	std::vector<bool> &cutPoints,
	std::vector<bool> &visitedBefore,
	std::vector<int> &time,
	std::vector<int> &minTime
) {
	time[curV] = curTime;
	minTime[curV] = curTime;
	curTime++;
	int childCount = 0;
	for (int nextV : g[curV]) {
		if (visitedBefore[nextV]) {
			continue;
		}
		if (time[nextV] == -1) {
			findCutPoints(nextV, curV, curTime, g, cutPoints, visitedBefore, time, minTime);
			childCount++;
			if (
				prevV != -1 && minTime[nextV] >= time[curV] ||
				prevV == -1 && childCount > 1
			) {
				cutPoints[curV] = true;
			}
			minTime[curV] = std::min(minTime[curV], minTime[nextV]);
		} else {
			minTime[curV] = std::min(minTime[curV], time[nextV]);
		}
	}
}

void print(const std::vector<int> &way) {
	printf("1");
	for (int v : way) {
		printf(" %d", v);
	}
	printf("\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	std::vector<std::vector<int>> g(nV);
	for (int iE = 0; iE < nE; iE++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		v1--;
		v2--;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	std::vector<bool> canVisit(nV, false);
	for (int v : g[0]) {
		canVisit[v] = true;
	}
	std::vector<bool> visitedBefore(nV);
	std::vector<bool> cutPoints(nV);
	std::vector<int> time(nV);
	std::vector<int> minTime(nV);
	std::vector<int> way;
	for (int i = 0; i < nV - 1; i++) {
		cutPoints.assign(nV, false);
		time.assign(nV, -1);
		minTime.assign(nV, -1);
		int curTime = 0;
		findCutPoints(0, -1, curTime, g, cutPoints, visitedBefore, time, minTime);
		int nextV = -1;
		for (int v = 1; v < nV; v++) {
			if (!visitedBefore[v] && canVisit[v] && !cutPoints[v]) {
				nextV = v;
				break;
			}
		}
		way.push_back(nextV + 1);
		visitedBefore[nextV] = true;
		for (int v : g[nextV]) {
			canVisit[v] = true;
		}
		for (int v : g[nextV]) {
			canVisit[v] = true;
		}
	}
	print(way);
	std::reverse(way.begin(), way.end());
	print(way);
	return 0;
}