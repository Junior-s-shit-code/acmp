#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

// count[2][10][10][n] - accepted; time 0.342/2.0, memory 12/16
// count[n][2][10][10] - MLE 17 test; time 0.436/2.0, memory 16/16

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MOD = (int)1e9 + 7;
    char buf[1 + 10000];
    scanf("%s", &buf);
    std::string str(buf);
    int n = (int)str.length();
    std::reverse(str.begin(), str.end());
    std::vector<std::vector<std::vector<std::vector<int>>>> count(2, std::vector<std::vector<std::vector<int>>>(10, std::vector<std::vector<int>>(10, std::vector<int>(n, 0))));

    for (int digitA = 0; digitA < 10; digitA++) {
        for (int digitB = 0; digitB < 10; digitB++) {
            int digitC = (digitA + digitB) % 10;
            int extra = (digitA + digitB) / 10;
            int charC = str[0] - '0';
            if (digitC != charC) {
                continue;
            }
            count[extra][digitA][digitB][0] = 1;
        }
    }

    for (int len = 1; len < n; len++) {
        for (int curA = 0; curA < 10; curA++) {
            for (int curB = 0; curB < 10; curB++) {
                count[0][curA][curB][len] = 0;
                count[1][curA][curB][len] = 0;
                for (int prevExtra = 0; prevExtra <= 1; prevExtra++) {
                    int curC = (curA + curB + prevExtra) % 10;
                    int extra = (curA + curB + prevExtra) / 10;
                    int curChar = str[len] - '0';
                    if (curC != curChar) {
                        continue;
                    }
                    for (int prevA = 0; prevA < 10; prevA++) {
                        for (int prevB = 0; prevB < 10; prevB++) {
                            if (curA != prevA && curB != prevB) {
                                count[extra][curA][curB][len] += count[prevExtra][prevA][prevB][len - 1];
                                count[extra][curA][curB][len] %= MOD;
                            }
                        }
                    }
                }
            }
        }
    }
    int sum = 0;
    for (int digitA = 1; digitA < 10; digitA++) {
        for (int digitB = 1; digitB < 10; digitB++) {
            sum += count[0][digitA][digitB][n - 1];
            sum %= MOD;
        }
    }
    printf("%d", sum);
    return 0;
}