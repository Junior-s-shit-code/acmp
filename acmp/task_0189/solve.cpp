#include <stdio.h>
#include <vector>
#include <set>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	std::vector <int> a(n);
	std::vector <int> fact(n);
	int curNum = 1;
	std::set <int> s;
	for (int i = 0; i < n; i++) {
		curNum *= (i + 1);
		int curIndex = n - i - 1;
		fact[curIndex] = curNum;
		s.insert(i + 1);
	}
	k--;
	int freeNum = n;
	for (int i = 0; i < n; i++) {
		int step = fact[i] / freeNum;
		freeNum--;
		int ansIndex = k / step;
		k %= step;
		int curIndex = 0;
		int ans;
		for (int item : s) {
			if (curIndex == ansIndex) {
				ans = item;
				break;
			}
			curIndex++;
		}
		s.erase(ans);
		printf("%d ", ans);
	}
	return 0;
}