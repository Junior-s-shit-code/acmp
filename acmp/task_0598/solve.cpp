#include <stdio.h>
#include <vector>
#include <cassert>

void print(
	const int n,
	const int len,
	const std::vector<int> &group
) {
	printf("%d\n", n - len + 1);
	const int UNDEF = -1;
	std::vector<int> a(n, UNDEF);
	int id = 1;
	for (int i = 0; i < len; i++) {
		a[group[i]] = id;
	}
	id++;
	for (int iMan = 0; iMan < n; iMan++) {
		if (a[iMan] == UNDEF) {
			a[iMan] = id;
			id++;
		}
		printf("%d ", a[iMan]);
	}
}

bool dfs(
	const int curId,
	const int curLen,
	const int maxLen,
	const int n,
	const std::vector<std::vector<bool>> &friends,
	std::vector<int> &group
) {
	for (int newFriend = curId; newFriend < n; newFriend++) {
		int curGroupId = curLen - 1;
		group[curGroupId] = newFriend;
		bool isFriends = true;

		for (int prevGroupId = 0; prevGroupId < curGroupId; prevGroupId++) {
			if (group[curGroupId] == group[prevGroupId] ||
				!friends[group[curGroupId]][group[prevGroupId]]
			) {
				isFriends = false;
				break;
			}
		}
		if (isFriends) {
			if (curLen == maxLen) {
				return true;
			} else if (dfs(curId + 1, curLen + 1, maxLen, n, friends, group)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int MAX_GROUP = 5;
	int n;
	scanf("%d", &n);
	std::vector<std::vector<bool>> friends(n, std::vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int val;
			scanf("%d", &val);
			friends[i][j] = (val == 1);
		}
	}
	std::vector<int> group(MAX_GROUP);
	for (int len = MAX_GROUP; len >= 1; len--) {
		if (dfs(0, 1, len, n, friends, group)) {
			print(n, len, group);
			return 0;
		}
	}
	return 0;
}