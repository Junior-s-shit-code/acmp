#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	int m = n;
	int x = n;
	for (int i = 0; i < k; i++) {
		int r;
		scanf("%d", &r);
		if (m > r) {
			m = r;
		}
		x = r - (n - x);
		if (x < 0) {
			x = 0;
		} 
	}
	printf("%d %d", x, m);
	return 0;
}