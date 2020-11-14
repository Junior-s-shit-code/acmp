#include <stdio.h>
#include <algorithm>
#include <vector>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int MOD = (int)1e6;
	const int INF = (int)1e9;
	const int UNDEFINED = -1;
	int n;
	scanf("%d", &n);
	std::vector<int> r(MOD, UNDEFINED);
	r[0] = 0;
	int curSum = 0;
	int bestLen = INF;
	int startI = UNDEFINED;
	for (int i = 1; i <= n; i++) {
		int value;
		scanf("%d", &value);
		curSum = (curSum + value) % MOD;
		if (r[curSum] != UNDEFINED) {
			int curLen = i - r[curSum];
			if (curLen < bestLen) {
				bestLen = curLen;
				startI = r[curSum];
			}
		}
		r[curSum] = i;
	}
	if (startI == UNDEFINED) {
		printf("-1");
	} else {
		printf("%d %d", bestLen, startI + 1);
	} 

	return 0; 
}