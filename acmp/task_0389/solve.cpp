#include <stdio.h>
#include <vector>
#include <algorithm>

void update(
    int id,
    int n,
    int &goodSegments,
    std::vector<bool> &goodCode,
    const std::vector<bool> &goodXor,
    const std::vector<int> &a
) {
    int leftId = id;
    int rightId = (id + 1) % n;
    int leftVal = a[(id - 1 + n) % n];
    int rightVal = a[rightId];
    int curVal = a[id];

    if (goodXor[leftVal ^ curVal] != goodCode[leftId]) {
        goodCode[leftId] = !goodCode[leftId];
        if (goodCode[leftId]) {
            goodSegments++;
        } else {
            goodSegments--;
        }
    }

    if (goodXor[rightVal ^ curVal] != goodCode[rightId]) {
        goodCode[rightId] = !goodCode[rightId];
        if (goodCode[rightId]) {
            goodSegments++;
        } else {
            goodSegments--;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::vector<bool> goodXor((1 << 16) + 1, false);
    for (int val = 1; val <= 1 << 16; val <<= 1) {
        goodXor[val] = true;
    }

    int exp;
    scanf("%d", &exp);
    int n = 1 << exp;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int goodSegments = 0;
    std::vector<bool> goodCode(n, false);
    for (int i = 0; i < n; i++) {
        int xorValue = a[i] ^ a[(i + 1) % n];
        goodCode[(i + 1) % n] = goodXor[xorValue];
        if (goodCode[(i + 1) % n]) {
            goodSegments++;
        }
    }
    int nQ;
    scanf("%d", &nQ);
    for (int q = 0; q < nQ; q++) {
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        std::swap(a[id1], a[id2]);
        update(id1, n, goodSegments, goodCode, goodXor, a);
        update(id2, n, goodSegments, goodCode, goodXor, a);
        if (goodSegments == n) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}