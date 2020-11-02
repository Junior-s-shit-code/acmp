#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector<int> len(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &len[i]);
	}
	std::sort(len.begin(), len.end());
	int curCount = 0;
	int prevCount = 0;
	int curValue = 0;
	int prevValue = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (curValue != len[i] && curCount >= 2) {
			prevValue = curValue;
			prevCount = curCount;
			curCount = 0;
			curValue = len[i];
		} else if (curValue != len[i]) {
			curValue = len[i];
			curCount = 0;
		}
		curCount++;
		if (curCount >= 2 && prevCount >= 2 && prevValue * 2 >= curValue) {
			curCount -= 2;
			prevCount -= 2;
			ans++;
		} else if (curCount >= 4) {
			curCount -= 4;
			ans++;
		}
	}
	
	printf("%d", ans);
	return 0;
}