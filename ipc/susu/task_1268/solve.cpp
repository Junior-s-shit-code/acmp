#include <stdio.h>
#include <vector>

std::vector<int> createPlayerField() {
    std::vector<int> a(7, 3);
    a[6] = 0;
    return a;
}

void moveOneHalf(int &index, int &stones, const int maxIndex, std::vector<int> &p) {
    while (stones > 0) {
        if (index >= maxIndex) {
            break;
        }
        p[index]++;
        index++;
        stones--;
    }
    if (index == maxIndex && stones != 0) {
        index = 0;
    }
}

bool move(int index, std::vector<int> &p1, std::vector<int> &p2) {
    int stones = p1[index];
    p1[index] = 0;
    index++;
    while (stones > 0) {
        moveOneHalf(index, stones, 7, p1);
        int rIndex = 6 - index;
        if (index == 7) {
            return true;
        } else if (p1[index - 1] == 1 && p2[rIndex] != 0) {
            p1[index - 1] = 0;
            p1[6] += p2[rIndex] + 1;
            p2[rIndex] = 0;
        }
        moveOneHalf(index, stones, 6, p2);
    }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int SIZE = 7;
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    std::vector<int> player1 = createPlayerField();
    std::vector<int> player2 = createPlayerField();
    bool isPlayerMove = true;
    for (int motion = 0; motion < n; motion++) {
        int start;
        scanf("%d", &start);
        if (isPlayerMove) {
            if (move(start - 1, player1, player2)) {
                continue;
            }
        } else {
            if (move(start - 1, player2, player1)) {
                continue;
            }
        }
        isPlayerMove = !isPlayerMove;
    }
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", player1[i]);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", player2[i]);
    }
    return 0;
}