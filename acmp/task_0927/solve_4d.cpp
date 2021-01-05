#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MOD = (int)1e9 + 7;
    char buf[1 + 10000];
    scanf("%s", &buf);
    std::string str(buf);
    int n = (int)str.length();
    std::reverse(str.begin(), str.end());
    std::vector<std::vector<std::vector<std::vector<int>>>> curCount(2, std::vector<std::vector<std::vector<int>>>(2, std::vector<std::vector<int>>(10, std::vector<int>(10, 0))));

    for (int digitA = 0; digitA < 10; digitA++) {
        for (int digitB = 0; digitB < 10; digitB++) {
            int digitC = (digitA + digitB) % 10;
            int extra = (digitA + digitB) / 10;
            int charC = str[0] - '0';
            if (digitC != charC) {
                continue;
            }
            curCount[0][extra][digitA][digitB] = 1;
        }
    }

    for (int len = 1; len < n; len++) {
        curCount[0].swap(curCount[1]);
        for (int curA = 0; curA < 10; curA++) {
            for (int curB = 0; curB < 10; curB++) {
                curCount[0][0][curA][curB] = 0;
                curCount[0][1][curA][curB] = 0;
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
                                curCount[0][extra][curA][curB] += curCount[1][prevExtra][prevA][prevB];
                                curCount[0][extra][curA][curB] %= MOD;
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
            sum += curCount[0][0][digitA][digitB];
            sum %= MOD;
        }
    }
    printf("%d", sum);
    return 0;
}