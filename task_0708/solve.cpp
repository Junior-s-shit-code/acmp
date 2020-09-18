#include <stdio.h>
#include <vector>
#include <algorithm>

int moveRabbit(const int &sizeI, const int &sizeJ, std::vector<std::vector<int>> &field) {
    int curJ = 1;
    int maxShrub = field[1][1];
    for (int j = 1; j <= sizeJ; j++) {
        if (field[1][j] >= maxShrub) {
            maxShrub = field[1][j];
            curJ = j;
        }
    }
    int ans = maxShrub;
    field[1][curJ] = 0; 
    for (int curI = 2; curI <= sizeI; curI++) {
        int dj;
        int maxValue = -1;
        for (int d = -1; d <= 1; d++) {
            if (curJ + d <= sizeJ && field[curI][curJ + d] >= maxValue) {
                maxValue = field[curI][curJ + d];
                dj = d;
            }
        }
        ans += maxValue;
        curJ = curJ + dj;
        field[curI][curJ] = 0;
    }
    return ans;
}

int moveHamster(const int &sizeI, const int &sizeJ, std::vector<std::vector<int>> &field) {
    std::vector<std::vector<int>> bestWay(sizeI + 2, std::vector<int>(sizeJ + 2, 0));
    for (int j = 1; j <= sizeJ; j++) {
        bestWay[sizeI][j] = field[sizeI][j];
    }
    for (int i = sizeI - 1; i >= 1; i--) {
        for (int j = 1; j <= sizeJ; j++) {
            bestWay[i][j] = field[i][j] + std::max({ 
                bestWay[i + 1][j - 1],
                bestWay[i + 1][j],
                bestWay[i + 1][j + 1] 
            });
        }
    }

    int curJ = 0;
    int ans = 0;
    for (int j = 1; j <= sizeJ; j++) {
        if (bestWay[1][j] >= ans) {
            ans = bestWay[1][j];
            curJ = j;
        }
    }
    
    for (int curI = 1; curI <= sizeI; curI++) {
        for (int dj = 1; dj >= -1; dj--) {
            if (curJ + dj <= sizeJ &&
                bestWay[curI][curJ] - field[curI][curJ] == bestWay[curI + 1][curJ + dj]) {
                field[curI][curJ] = 0;
                curJ += dj;
                break;
            }
        }
    }

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    int sum = 0;
    std::vector<std::vector<int>> field(sizeI + 2, std::vector<int>(sizeJ + 2, 0));
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            scanf("%d", &field[i][j]);
            sum += field[i][j];
        }
    }

    int ansRabbits = 0, ansHamsters = 0;
    for (int move = 0; ansRabbits + ansHamsters < sum; move = (move + 1) % 2) {
        if (move == 0) {
            ansRabbits += moveRabbit(sizeI, sizeJ, field);
        } else {
            ansHamsters += moveHamster(sizeI, sizeJ, field);
        }
    }
    printf("%d %d", ansRabbits, ansHamsters);
    return 0;
}