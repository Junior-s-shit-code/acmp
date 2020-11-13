#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <unordered_set>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector<int> h(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	char buf[1 + 100];
	scanf("%s", &buf);
	std::string str(buf);
	int iRobot = 0;
	int move = 1;
	bool isTake = false;
	int len = (int)str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == 'F') {
			if (i + 1 < len && str[i + 1] == '*') {
				i++;
				while (0 <= iRobot + move &&
					   iRobot + move < n &&
					   h[iRobot + move] == h[iRobot]
				) {
					iRobot += move;
				}
			} else {
				if (0 <= iRobot + move &&
					iRobot + move < n &&
					h[iRobot + move] == h[iRobot]
				) {
					iRobot += move;
				}
			}
		} else if (str[i] == 'R') {
			move *= -1;
		} else if (str[i] == 'T') {
			if (!isTake &&
				0 <= iRobot + move &&
				iRobot + move < n
			) {
				int diffH = h[iRobot + move] - h[iRobot];
				if (0 <= diffH && diffH <= 2) {
					h[iRobot + move]--;
					isTake = true;
				}
			}
		} else if (str[i] == 'D') {
			if (isTake &&
				0 <= iRobot + move &&
				iRobot + move < n
			) {
				int diffH = h[iRobot + move] - h[iRobot];
				if (-1 <= diffH && diffH <= 1) {
					h[iRobot + move]++;
					isTake = false;
				}
			}
		} else if (str[i] == 'C') {
			if (0 <= iRobot + move &&
				iRobot + move < n
			) {
				int diffH = std::abs(h[iRobot + move] - h[iRobot]);
				if (diffH == 1) {
					iRobot += move;
				}
			}
		}
	}
	printf("%d\n", iRobot + 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", h[i]);
	}
	return 0;
}