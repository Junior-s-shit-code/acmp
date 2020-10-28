#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

int sumDigits(int num) {
	int ans = 0;
	while (num > 0) {
		int d = num % 10;
		ans += d * d;
		num /= 10;
	}
	return ans;
}

bool isWanted(int num, std::vector<bool> &is, std::vector<bool> &was) {
	if (!was[num]) {
		was[num] = true;
		is[num] = false;
		if (isWanted(sumDigits(num), is, was)) {
			is[num] = true;
		}
	}
	return is[num];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::vector<bool> is(81 * 100 + 2, false);
	std::vector<bool> was(81 * 100 + 2, false);
	was[0] = was[1] = true;
	is[1] = true;
	int curNum = 0;
	char c;
	while (true) {
		int code = scanf(" %c", &c);
		if (code == EOF) {
			break;
		}
		int val = c - '0';
		curNum += val * val;
	}
	printf(isWanted(curNum, is, was) ? "YES" : "NO");
	return 0;
}