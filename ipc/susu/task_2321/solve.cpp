#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>

void findBest(std::vector<int> &v, std::vector<int> &min) {
	for (int i = 0; i < 6; i++) {
		std::swap(v[0], v[1]);
		std::swap(v[1], v[2]);
		std::swap(v[2], v[3]);
		std::swap(v[3], v[4]);
		std::swap(v[4], v[5]);
		min = std::min(min, v);
	}
}

std::vector<int> getMinV(std::vector<int> &v) {
	std::vector<int> ans = v;
	findBest(v, ans);
	std::reverse(v.begin(), v.end());
	findBest(v, ans);
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector<std::vector<int>> all(n);
	for (int i = 0; i < n; i++) {
		std::vector<int> v(6);
		for (int j = 0; j < 6; j++) {
			scanf("%d", &v[j]);
		}
		all[i] = getMinV(v);
	}
	std::sort(all.begin(), all.end());
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (all[i] != all[i - 1]) {
			ans++;
		}
	}
	printf("%d", ans);
	return 0; 
}