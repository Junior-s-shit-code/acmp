#include <stdio.h>
#include <vector>
#include <algorithm>

void updateSegment(
    int &goodSegments,
    const int value,
    const int id,
    const std::vector<bool> &goodXor,
    std::vector<bool> &code
) {
    if (goodXor[value] != code[id]) {
        code[id] = !code[id];
        if (code[id]) {
            goodSegments++;
        } else {
            goodSegments--;
        }
    }
}

void update(
    int &goodSegments,
    const int id,
    const int n,
    const std::vector<bool> &goodXor,
    const std::vector<int> &a, 
    std::vector<bool> &code
) {
    int curValue = a[id];

    int leftId = id;
    int leftValue = a[(id - 1 + n) % n];
    updateSegment(goodSegments, curValue ^ leftValue, leftId, goodXor, code);

    int rightId = (id + 1) % n;
    int rightValue = a[rightId];
    updateSegment(goodSegments, curValue ^ rightValue, rightId, goodXor, code);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::vector<bool> goodXor((1 << 16) + 1, false);
    for (int val = 1; val <= 1 << 16; val <<= 1) {
        goodXor[val] = true;
    }

    int binPow;
    scanf("%d", &binPow);
    int n = 1 << binPow;
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
        update(goodSegments, id1, n, goodXor, a, goodCode);
        update(goodSegments, id2, n, goodXor, a, goodCode);
        if (goodSegments == n) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}