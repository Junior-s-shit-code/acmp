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
	int ans = 0;
	int bestTime = time;
	for (int i = 0; i < 10; i++) {
		int curValue = (time - b * i) / a + i;
		int curTime = (time - b * i) % a;
		if (curTime < 0) {
			continue;
		}
		if ((bestTime > curTime) || (bestTime == curTime && curValue > ans)) {
			ans = curValue;
			bestTime = curTime;
		}
	}
	printf("%d", ans);
	if (bestTime) {
		printf(" %d", bestTime);
	}
	return 0;
}