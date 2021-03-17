#include <stdio.h>
#include <vector>
#include <algorithm>

const int n = 3;
const char FREE = '#';
const int DRAW = 4;

bool win(const std::vector<std::vector<char>> &a) {
    return a[0][0] == a[0][1] && a[0][1] == a[0][2] && a[0][0] != FREE ||
        a[1][0] == a[1][1] && a[1][1] == a[1][2] && a[1][0] != FREE ||
        a[2][0] == a[2][1] && a[2][1] == a[2][2] && a[2][0] != FREE ||

        a[0][0] == a[1][0] && a[1][0] == a[2][0] && a[0][0] != FREE ||
        a[0][1] == a[1][1] && a[1][1] == a[2][1] && a[0][1] != FREE ||
        a[0][2] == a[1][2] && a[1][2] == a[2][2] && a[0][2] != FREE ||

        a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[1][1] != FREE ||
        a[2][0] == a[1][1] && a[1][1] == a[0][2] && a[1][1] != FREE;
}

int dfs(
    const int step,
    const std::vector<char> &move,
    std::vector<std::vector<char>> &a
) {
    if (win(a)) {
        return step;
    } else if (step == 3) {
        return DRAW;
    }
    bool firstWinX = false;
    int countWinO = 0;
    int countWinX = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == FREE) {

                a[i][j] = move[step % 2];
                int value = dfs(step + 1, move, a);
                a[i][j] = FREE;

                if (step == 0 && value == 1) {
                    return 1;
                } else if (step == 0 && value == 2) {
                    countWinO++;
                } else if (step == 0 && value == 3) {
                    return 3;
                } 

                if (step == 1 && value == 2) {
                    return 2;
                } else if (step == 1 && value == 3) {
                    countWinX++;
                }

                if (step == 2 && value == 3) { 
                    return 3;
                } 
            }
        }
    }
    if (step == 0 && countWinO == 3) {
        return 2; 
    } else if (step == 1 && countWinX == 2) {
        return 3; 
    } else {
        return DRAW;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::vector<std::vector<char>> a(n, std::vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    std::vector<char> move{ 'X', 'O' };
    int value = dfs(0, move, a);
    if (value == 1 || value == 3) {
        printf("Crosses win");
    } else if (value == 2) {
        printf("Ouths win");
    } else {
        printf("Draw");
    }
    return 0;
}