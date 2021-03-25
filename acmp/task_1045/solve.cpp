#include <stdio.h>
#include <vector>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector<int> a(n + 1);
	a[1] = 1;
	int best = 1;
	int bestId = 1;
	for (int i = 2; i <= n; i++) {
		a[i] = best + i - bestId;

		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0 && a[i] > a[j] + a[i / j]) {
				a[i] = a[j] + a[i / j];
				best = a[i];
				bestId = i;
			}
		}
	}
	printf("%d", a[n]);
	return 0;
}