#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector<int> diff(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &diff[i]);
	}
	for (int i = 0; i < n; i++) {
		int value;
		scanf("%d", &value);
		diff[i] -= value;
	}
	int limit = INT_MAX;
	int curDiff = 0;
	for (int i = 0; i < n; i++) {
		curDiff += diff[i];
		limit = std::min(limit, curDiff);
	}
	for (int i = 0; i < n; i++) {
		if (limit  >= 0) {
			printf("%d ", i + 1);
		}
		limit -= diff[i]; //limit += (diff[i] * -1)
	}
	return 0;
}