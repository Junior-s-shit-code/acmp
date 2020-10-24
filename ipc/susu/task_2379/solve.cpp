#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <iterator>

void build(const int left,
		   const int right,
		   const int pos,
		   const std::vector<int> &a,
		   std::vector<std::vector<int>> &tree) {
	if (left == right) {
		tree[pos] = std::vector<int>{ a[left] };
	} else {
		int leftEnd = (left + right) >> 1;
		int rightBegin = leftEnd + 1;
		int iLeft = (pos << 1) + 1;
		int iRight = (pos << 1) + 2;
		build(left, leftEnd, iLeft, a, tree);
		build(rightBegin, right, iRight, a, tree);
		tree[pos].reserve((int)tree[iLeft].size() + (int)tree[iRight].size());
		std::merge(tree[iLeft].begin(), tree[iLeft].end(),
				   tree[iRight].begin(), tree[iRight].end(),
				   std::back_inserter(tree[pos]));
	}
}

int getLower(const int value,
			 int qLeft, int qRight,
			 const int pos,
			 int left, int right,
			 std::vector<std::vector<int>> &tree) {
	if (qLeft > qRight) {
		return 0;
	}
	qLeft = std::max(qLeft, left);
	qRight = std::min(qRight, right);
	if (qLeft == left && qRight == right) {
		return std::upper_bound(tree[pos].begin(), tree[pos].end(), value) - tree[pos].begin();
	} else {
		int leftEnd = (left + right) >> 1;
		int rightBegin = leftEnd + 1;
		int iLeft = (pos << 1) + 1;
		int iRight = (pos << 1) + 2;
		return getLower(value, qLeft, qRight, (pos << 1) + 1, left, leftEnd, tree) + 
			getLower(value, qLeft, qRight, (pos << 1) + 2, rightBegin, right, tree);
	}
}

int getUpper(const int value,
			 int qLeft, int qRight,
			 const int pos,
			 int left, int right,
			 std::vector<std::vector<int>> &tree) {
	if (qLeft > qRight) {
		return 0;
	}
	qLeft = std::max(qLeft, left);
	qRight = std::min(qRight, right);
	if (qLeft == left && qRight == right) {
		return (int)tree[pos].size() - (std::upper_bound(tree[pos].begin(), tree[pos].end(), value - 1) - tree[pos].begin());
	} else {
		int leftEnd = (left + right) >> 1;
		int rightBegin = leftEnd + 1;
		int iLeft = (pos << 1) + 1;
		int iRight = (pos << 1) + 2;
		return getUpper(value, qLeft, qRight, (pos << 1) + 1, left, leftEnd, tree) +
			getUpper(value, qLeft, qRight, (pos << 1) + 2, rightBegin, right, tree);
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	std::vector<std::vector<int>> tree(4 * n);
	build(0, n -1, 0, a, tree);
	for (int i = 0; i < n; i++) {
		if (getLower(a[i], 0, i - 1, 0, 0, n - 1, tree) >=
			getUpper(a[i], i + 1, n - 1, 0, 0, n - 1, tree)) {
			printf("%d", i + 1);
			return 0;
		}
	}
	return 0;
}