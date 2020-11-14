#include <stdio.h>
#include <algorithm>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, time;
	scanf("%d %d %d", &a, &b, &time);
	if (a > b) {
		std::swap(a, b);
	}
	const int COUNT_BURGERS_FOR_BEST_ANS = 10;
	int ans = 0;
	int minTimeRemain = time;
	
	for (int i = 0; i < COUNT_BURGERS_FOR_BEST_ANS; i++) {
		int curValue = (time - b * i) / a + i;
		int curTime = (time - b * i) % a;
		if (curTime < 0) {
			continue;
		}
		if (minTimeRemain > curTime || 
			(minTimeRemain == curTime && curValue > ans)
		) {
			ans = curValue;
			minTimeRemain = curTime;
		}
	}
	printf("%d", ans);
	if (minTimeRemain > 0) {
		printf(" %d", minTimeRemain);
	}
	return 0;
}