#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>

void findCutPoints(
	const int curV,
	const int prevV,
	int &curTime,
	std::vector<int> &time,
	std::vector<int> &minTime,
	const std::vector<std::vector<int>> &g,
	std::vector<std::vector<int>> &sizes
) {
	time[curV] = curTime;
	minTime[curV] = curTime;
	curTime++;
	int childCount = 0;
	for (int nextV : g[curV]) {
		if (nextV == prevV) {
			continue;
		}
		if (time[nextV] == -1) {
			int before = curTime;
			findCutPoints(nextV, curV, curTime, time, minTime, g, sizes);
			int after = curTime;
			childCount++;
			if (
				prevV == -1 && childCount > 1 || prevV != -1 && minTime[nextV] >= time[curV]
			) {
				sizes[curV].push_back(after - before);
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
	std::vector<std::vector<int>> g(nV);
	for (int iE = 0; iE < nE; iE++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		v1--;
		v2--;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	std::vector<int> time(nV, -1);
	std::vector<int> minTime(nV, -1);
	std::vector<std::vector<int>> sizes(nV); //[v] -> min size of component, in which 'v' point consist
	int curTime = 0;
	findCutPoints(0, -1, curTime, time, minTime, g, sizes);
	for (int iV = 0; iV < nV; iV++) {
		int ans = 0;
		if (!sizes[iV].empty()) {
			int sum = 0;
			for (int item : sizes[iV]) {
				sum += item;
			}
			sizes[iV].push_back(nV - 1 - sum);
			for (int item : sizes[iV]) {
				ans += item * (nV - 1 - item);
			}
		}
		ans >>= 1;
		ans += nV - 1;
		printf("%d\n", ans);
	}
	return 0;
}