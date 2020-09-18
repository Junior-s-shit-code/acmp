#include <stdio.h>
#include <vector>
#include <algorithm>

struct Point {

    int i;

    int j;
};

void moveRabbit(const int &sizeI, const int &sizeJ, int &ansRabbits, std::vector<std::vector<int>> &field) {
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
        int right = field[curI][curJ + 1];
        int mid = field[curI][curJ];
        int left = field[curI][curJ - 1];
        if (curJ + 1 <= sizeJ && right >= mid && right >= left) { 
            field[curI][curJ + 1] = 0;
            ans += right;
            curJ = curJ + 1;
        } else if (mid >= right && mid >= left) {
            field[curI][curJ] = 0;
            ans += mid;
        } else {
            field[curI][curJ - 1] = 0;
            ans += left;
            curJ = curJ - 1;
        }
    }
    ansRabbits += ans;
}

void moveHamster(const int &sizeI, const int &sizeJ, int &ansHamsters, std::vector<std::vector<int>> &field) {
    std::vector<std::vector<int>> a(sizeI + 2, std::vector<int>(sizeJ + 2, 0));
    std::vector<std::vector<Point>> prev(sizeI + 2, std::vector<Point>(sizeJ + 2, Point{ -1, -1 }));
    for (int j = 1; j <= sizeJ; j++) {
        a[sizeI][j] = field[sizeI][j];
    }
    for (int i = sizeI - 1; i >= 1; i--) {
        for (int j = 1; j <= sizeJ; j++) {
            int left = a[i + 1][j - 1];
            int mid = a[i + 1][j];
            int right = a[i + 1][j + 1];
            if (right >= mid && right >= left) {
                a[i][j] = field[i][j] + right;
                prev[i][j] = Point{ i + 1, j + 1 };
            } else if (mid >= right && mid >= left) {
                a[i][j] = field[i][j] + mid;
                prev[i][j] = Point{ i + 1, j };
            } else {
                a[i][j] = field[i][j] + left;
                prev[i][j] = Point{ i + 1, j - 1 };
            }
        }
    }
    int startJ = 0;
    int ans = 0;
    for (int j = 1; j <= sizeJ; j++) {
        if (a[1][j] >= ans) {
            ans = a[1][j];
            startJ = j;
        }
    }
    ansHamsters += ans;
    Point toNull = { 1, startJ };
    while (!(toNull.i == -1 || toNull.j == -1)) {
        field[toNull.i][toNull.j] = 0;
        toNull = prev[toNull.i][toNull.j];
    }
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
            moveRabbit(sizeI, sizeJ, ansRabbits, field);
        } else {
            moveHamster(sizeI, sizeJ, ansHamsters, field);
        }
    }
    printf("%d %d", ansRabbits, ansHamsters);
    return 0;
}