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
	int prevPairLen = 0;
	int maxCount = 0;

	for (int i = 0; i + 1 < n; ) {
		if (len[i] == len[i + 1]) {
			if (prevPairLen == 0) {
				prevPairLen = len[i];
			} else {
				if (len[i] <= 2 * prevPairLen) {
					maxCount++;
					prevPairLen = 0;
				} else {
					prevPairLen = len[i];
				}
			}
			i += 2;
		} else {
			i++;
		}
	}
	printf("%d", maxCount);
	return 0;
}