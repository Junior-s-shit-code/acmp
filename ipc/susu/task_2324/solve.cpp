#include <stdio.h>
#include <algorithm>
#include <vector>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int MOD = (int)1e6;
	const int INF = (int)1e9;
	int n;
	scanf("%d", &n);
	std::vector<int> a(n);
	std::vector<int> r(MOD, -2);
	r[0] = -1;
	int curSum = 0;
	int bestLen = INF;
	int startI = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		curSum += a[i];
		curSum %= MOD;
		if (r[curSum] != -2) {
			int curLen = i - r[curSum];
			if (curLen < bestLen) {
				bestLen = curLen;
				startI = r[curSum] + 1;
			} else if (curLen == bestLen) {
				startI = std::min(startI, r[curSum] + 1);
			}
		}
		r[curSum] = i;
	}
	if (startI == -1) {
		printf("-1");
	} else {
		printf("%d %d", bestLen, startI + 1);
	} 

	return 0; 
}