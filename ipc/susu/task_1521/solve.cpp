#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>

const int LIMIT = (int)1e8;

struct Pair {

    int a;

    int b;

    int sum;
};

void generatePairs(std::vector<Pair> &pairs) {
    const int MAX_PYRAMIDAL_ID = 668;
    const int MAX_TRIANGULAR_ID = 843;
    for (int a = 1; a <= MAX_PYRAMIDAL_ID; a++) {
        int squareValue = a * (a + 1) * (2 * a + 1) / 6;
        for (int b = 1; b <= MAX_TRIANGULAR_ID; b++) {
            int triangleValue = b * (b + 1) * (b + 2) / 6;
            int sum = squareValue + triangleValue;
            if (sum > LIMIT) {
               break;
            }
            pairs.push_back(Pair{ a, b, sum });
        }
    }
}

int binSearch(int value, const std::vector<Pair> &pairs) {
    int left = 0;
    int right = (int)pairs.size();
    while (left + 1 < right) {
        int mid = (left + right) >> 1;
        if (pairs[mid].sum > value) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::vector<Pair> pairs;
    generatePairs(pairs);
    std::sort(pairs.begin(), pairs.end(), [](const Pair &left, const Pair &right) {
        if (left.sum == right.sum) {
            return left.a > right.a;
        }
        return left.sum < right.sum;
    });
    while (true) {
        int value;
        scanf("%d", &value);
        if (value == 0) {
            break;
        }
        int index = binSearch(value, pairs);
        assert(0 <= index && index < (int)pairs.size());
        Pair ans = pairs[binSearch(value, pairs)];
        printf("%d %d\n", ans.a, ans.b);
    }
    return 0;
}