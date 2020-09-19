#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector <int> coins(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &coins[i]);
	}
	int maxToGet;
	scanf("%d", &maxToGet);
	std::vector <int> sumFrom(n + 1);
	sumFrom[n] = coins[n];
	for (int i = n - 1; i > 0; i--) {
		sumFrom[i] = sumFrom[i + 1] + coins[i];
	}
	std::vector<std::vector<int>> maxWin(n + 1, std::vector<int>(maxToGet + 1));
	for (int i = 1; i <= maxToGet; i++) {
		maxWin[n][i] = coins[n];
	}
	for (int first = n - 1; first > 0; first--) {
		for (int toGet = 1; toGet <= maxToGet; toGet++) {
			if (toGet == 1) {
				maxWin[first][toGet] = sumFrom[first] - maxWin[first + 1][1];
			} else if (first + toGet > n) {
				maxWin[first][toGet] = sumFrom[first];
			} else {
				maxWin[first][toGet] = std::max(
					maxWin[first][toGet - 1],
					sumFrom[first] - maxWin[first + toGet][toGet]
				);
			}
		}
	}
	printf("%d", maxWin[1][maxToGet]);
	return 0;
}