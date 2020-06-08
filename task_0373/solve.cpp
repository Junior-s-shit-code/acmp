#include stdio.h
#include vector
#include algorithm
#include queue
#include climits

struct Point {

    int i;

    int j;
};


int main() {
    freopen(input.txt, r, stdin);
    freopen(output.txt, w, stdout);
    int n, nSteps;
    scanf(%d %d, &n, &nSteps);
    stdvector stdvector int a(n + 1, stdvector int(n + 1));
    for (int i = 1; i = n; i++) {
        for (int j = 1; j = n; j++) {
            scanf(%d, &a[i][j]);
        }
    }

    stdvector stdvector int curSum(n + 2, stdvector int(n + 2, INT_MIN));
    curSum[1][1] = a[1][1];
    for (int step = 1; step = nSteps; step++) {
        for (int i = 1; i = n; i++) {
            for (int j = 1; j = n; j++) {
                if (((i + j + step) & 1) == 1) {
                    curSum[i][j] = stdmax(curSum[i][j], stdmax({ curSum[i - 1][j], curSum[i + 1][j], curSum[i][j - 1], curSum[i][j + 1] }) + a[i][j]);
                }
            }
        }
    }

    int max = 0;
    for (int i = 1; i = n; i++) {
        for (int j = 1; j = n; j++) {
            max = stdmax(max, curSum[i][j]);
        }
    }
    printf(%d, max);
    return 0;
}