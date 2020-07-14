#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int fullCost, freeCost;
	scanf("%d %d", &fullCost, &freeCost);
	int ans = fullCost;
	for (int i = 4; i >= 1; i--) {
		int prevBottles = (ans - fullCost) / freeCost + 1;
		int extra = ans - prevBottles * freeCost;
		ans = extra + prevBottles * fullCost;
	}
	printf("%d", ans);
	return 0;
}