#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int INF = (int)1e9 + 1;
	int sizeI;
	scanf("%d", &sizeI);
	std::vector<int> a(sizeI + 1, INF);
	for (int i = 0; i < sizeI; i++) {
		scanf("%d", &a[i]);
	}
	int sizeJ;
	scanf("%d", &sizeJ);
	std::vector<int> b(sizeJ + 1, INF);
	for (int i = 0; i < sizeJ; i++) {
		scanf("%d", &b[i]);
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	if (a[sizeI - 1] != b[sizeJ - 1]) {
		printf("NO");
		return 0;
	}
	int curI = 0, curJ = 0;
	int ans = 0;
	while (!(curI == sizeI && curJ == sizeJ)) {
		if (a[curI] == b[curJ]) {
			curI++;
			curJ++;
		} else if (a[curI] < b[curJ]) {
			curI++;
		} else {
			curJ++;
		}
		ans++;
	}
	printf("%d", ans);
	return 0;
}