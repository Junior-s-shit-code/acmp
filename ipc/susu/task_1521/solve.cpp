#include <stdio.h>
#include <vector>
#include <algorithm>

inline int binSearch(const int value, int &curH, const std::vector<int> &s) {
    int left = 0;
    int right = (int)s.size();
    while (left + 1 < right) {
        int mid = ((left + right) >> 1);
        if (s[mid] <= value) {
            left = mid;
        } else {
            right = mid;
        }
    }
    curH = left;
    return s[left];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int LIMIT = (int)1e8;

    std::vector<int> b = { 0 };

    int value = 1;
    int curSum = 0;
    for (int value = 1, index = 1; curSum <= LIMIT; index++, value += index) {
        curSum += value;
        b.push_back(curSum);
    }

    while (true) {
        scanf("%d", &value);
        if (value == 0) {
            break;
        }
        int bestAns = (int)1e8;
        int bestFirst = -1;
        int bestSecond = -1;
        int curSum = 0;
        int add = 1;
        for (int i = 1; i < 671; i++) {
            curSum += add * add;
            add++;
            int remain = value - curSum;
            if (remain <= 0) {
                break;
            } else {
                int curH;
                int second = binSearch(remain, curH, b);
                if (remain - second < bestAns) {
                    bestAns = remain - second;
                    bestFirst = i;
                    bestSecond = curH;
                    if (bestAns == 0) {
                        break;
                    }
                }
            }
        }
        printf("%d %d\n", bestFirst, bestSecond);
    }
    return 0;
}