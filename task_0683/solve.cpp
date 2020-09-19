#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	const int INF = 2000000 + 1;
	std::vector<std::vector<int>> minScore(n, std::vector<int> (n));
	for (int len = 2; len <= n; len++) {
		for (int left = 0; left + len - 1 < n; left++) {
			int right = left + len - 1;
			minScore[left][right] = INF;
			if (len == 2) {
				minScore[left][right] = 0;
			} else {
				for (int mid = left + 1; mid < right; mid++) {
					minScore[left][right] = std::min(
						minScore[left][right],
						a[mid] * (a[left] + a[right]) + minScore[left][mid] + minScore[mid][right]
					);
				}
			}
		}
	}
	printf("%d", minScore[0][n - 1]);
	return 0;
}