#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

std::string solve(std::string str) {
	int n = (int)str.length();
	std::string left = str.substr(0, n / 2);
	std::reverse(left.begin(), left.end());
	std::string right = str.substr(n / 2 + (n & 1), n / 2);
	if (left > right) {
		right = left;
		return str.substr(0, n / 2 + (n & 1)) + right;
	} else {
		int start = n / 2;
		if (n & 1) {
			start++;
		}
		int extra = 1;
		for (int i = start - 1; i >= 0; i--) {
			int value = str[i] - '0' + extra;
			extra = value / 10;
			value %= 10;
			str[i] = value + '0';
			if (extra == 0) {
				break;
			}
		}
		if (extra == 1) {
			str = '1';
			for (int i = 0; i < n; i++) {
				str += '0';
			}
		}
		n = (int)str.length();
		std::string left = str.substr(0, n / 2);
		std::reverse(left.begin(), left.end());
		std::string right = str.substr(n / 2 + (n & 1), n / 2);
		right = left;
		right[(int)right.size() - 1]--;
		return solve(str.substr(0, n / 2 + (n & 1)) + right);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char buf[2 + 100];
	scanf("%s", &buf);
	std::string str(buf);
	if ((int)str.size() == 1 && str != "9") {
		str[0]++;
		printf("%s", str.c_str());
	} else {
		printf("%s", solve(str).c_str());
	}
	return 0;
}