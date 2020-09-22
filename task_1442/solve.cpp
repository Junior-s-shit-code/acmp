#include <stdio.h>
#include <vector>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, nSegments;
	scanf("%d %d", &n, &nSegments);
	std::vector<int> max(n, 1);
	std::vector<int> fromIndex(n, -1);
	std::vector<int> len(nSegments);
	for (int q = 0; q < nSegments; q++) {
		int left, right, maxValue;
		scanf("%d %d %d", &left, &right, &maxValue);
		int l = right - left + 1;
		len[q] = l;
		for (int i = left - 1; i < right; i++) {
			if (fromIndex[i] == -1) {
				max[i] = maxValue;
				fromIndex[i] = q;
			} else if (maxValue < max[i]) {
				max[i] = maxValue;
				len[fromIndex[i]]--;
				if (len[fromIndex[i]] < 1) {
					printf("FAIL");
					return 0;
				}
				fromIndex[i] = q;
			}
		}
	}
	printf("EASY\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", max[i]);
	}
	return 0;
}