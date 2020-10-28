#include <stdio.h>
#include <vector>
#include <algorithm>

struct Stick {

	int value;

	int count;
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a.begin(), a.end());
	std::vector<Stick> sticks;
	for (int i = 0; i < n; i++) {
		Stick newStick = { a[i], 1 };
		while (i + 1 < n && a[i + 1] == a[i]) {
			newStick.count++;
			i++;
		}
		newStick.count -= (newStick.count & 1);
		if (newStick.count > 0) {
			sticks.push_back(newStick);
		}
	}
	int ans = 0;
	int iPrev = 0;
	for (int i = 0; i < (int)sticks.size(); i++) {
		while (true) {
			if (sticks[iPrev].count == 0 || sticks[iPrev].value * 2 < sticks[i].value) {
				iPrev++;
				continue;
			}

			if (iPrev < i) {
				int counter = std::min(sticks[iPrev].count, sticks[i].count);
				sticks[iPrev].count -= counter;
				sticks[i].count -= counter;
				ans += (counter >> 1);
			} else if (iPrev == i) {
				int counter = sticks[i].count / 4;
				sticks[i].count -= counter * 4;
				ans += counter;
			}

			if (sticks[i].count == 0 || (sticks[i].count == 2 && i == iPrev)) {
				break;
			} else {
				iPrev++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}