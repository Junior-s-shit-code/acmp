#include <stdio.h>
#include <vector>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int nQ;
	scanf("%d", &nQ);
	for (int q = 0; q < nQ; q++) {
		int tapIndex;
		scanf("%d", &tapIndex);
		a[tapIndex]--;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] >= 0) {
			printf("no\n");
		} else {
			printf("yes\n");
		}
	}
	return 0;
}