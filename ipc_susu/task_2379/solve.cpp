#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>

class SegmentTree {

    int size;

    std::vector<std::vector<int>> t;

    void build(int pos, int left, int right, const std::vector<int> &a) {
        if (left == right) {
            t[pos].push_back(a[left]);
            return;
        }
        int mid = left + ((right - left) >> 1);
        build((pos << 1) + 1, left, mid, a);
        build((pos << 1) + 2, mid + 1, right, a);
        std::merge(
            t[(pos << 1) + 1].begin(), t[(pos << 1) + 1].end(),
            t[(pos << 1) + 2].begin(), t[(pos << 1) + 2].end(),
            std::back_inserter(t[pos])
        );
    }

    int queryGreaterOrEqual(int pos, int left, int right, int qLeft, int qRight, int qValue) const {
        if (qRight < left || right < qLeft) {
            return 0;
        }
        if (qLeft <= left && right <= qRight) {
            return t[pos].end() - std::lower_bound(t[pos].begin(), t[pos].end(), qValue);
        }
        int mid = left + ((right - left) >> 1);
        int countLeft = queryGreaterOrEqual((pos << 1) + 1, left, mid, qLeft, qRight, qValue);
        int countRight = queryGreaterOrEqual((pos << 1) + 2, mid + 1, right, qLeft, qRight, qValue);
        return countLeft + countRight;
    }

    int queryLessOrEqual(int pos, int left, int right, int qLeft, int qRight, int qValue) const {
        if (qRight < left || right < qLeft) {
            return 0;
        }
        if (qLeft <= left && right <= qRight) {
            return std::upper_bound(t[pos].begin(), t[pos].end(), qValue) - t[pos].begin();
        }
        int mid = left + ((right - left) >> 1);
        int countLeft = queryLessOrEqual((pos << 1) + 1, left, mid, qLeft, qRight, qValue);
        int countRight = queryLessOrEqual((pos << 1) + 2, mid + 1, right, qLeft, qRight, qValue);
        return countLeft + countRight;
    }

public:

    SegmentTree(const std::vector<int> &a) {
        size = (int)a.size();
        t.resize(4 * size);
        build(0, 0, size - 1, a);
    }

    int queryGreaterOrEqual(int qLeft, int qRight, int qValue) const {
        return queryGreaterOrEqual(0, 0, size - 1, qLeft, qRight, qValue);
    }

    int queryLessOrEqual(int qLeft, int qRight, int qValue) const {
        return queryLessOrEqual(0, 0, size - 1, qLeft, qRight, qValue);
    }

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
    SegmentTree tree(a);
    for (int i = 0; i < n; i++) {
        int countLessLeft;
        if (i == 0) {
            countLessLeft = 0;
        } else {
            countLessLeft = tree.queryLessOrEqual(0, i - 1, a[i]);
        }
        int countGreaterRight;
        if (i == n - 1) {
            countGreaterRight = 0;
        } else {
            countGreaterRight = tree.queryGreaterOrEqual(i + 1, n - 1, a[i]);
        }
        if (countLessLeft >= countGreaterRight) {
            printf("%d", i + 1);
            return 0;
        }
    }
    return 0;
}