#include <stdio.h>
#include <vector>
#include <string>

struct Info {

    bool possible;

    int nOnes;

    int last;

    int prevResult;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int f[2][2];
    scanf("%1d%1d%1d%1d", &f[0][0], &f[0][1], &f[1][0], &f[1][1]);
    std::vector <std::vector <Info>> info(2, std::vector <Info>(1 + n, Info{ false, 0, -1, -1 })); 
    info[0][1] = Info{ true, 0, 0, -1 };
    info[1][1] = Info{ true, 1, 1, -1 };
    for (int len = 2; len <= n; len++) {
        for (int prevResult = 0; prevResult <= 1; prevResult++) {
            if (!info[prevResult][len - 1].possible) {
                continue;
            }
            for (int lastDigit = 0; lastDigit <= 1; lastDigit++) {
                int result = f[prevResult][lastDigit];
                int nOnes = info[prevResult][len - 1].nOnes + lastDigit;
                if (!info[result][len].possible || info[result][len].nOnes < nOnes) {
                    info[result][len] = Info{ true, nOnes, lastDigit, prevResult };
                }
            }
        }
    }

    if (!info[1][n].possible) {
        printf("No solution");
        return 0;
    }

    std::string ans;
    int result = 1;
    int len = n;
    while (len > 0) {
        ans.insert(ans.begin(), (char)(info[result][len].last + '0'));
        result = info[result][len].prevResult;
        len--;
    }
    printf("%s", ans.c_str());
    return 0;
}