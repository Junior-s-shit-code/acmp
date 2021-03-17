#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

const int N_SQUARES = 2;

bool build(
    const int curWord,
    const int curSquare,
    const int n,
    const std::vector<std::string> &a,
    std::vector<bool> &used,
    std::vector<std::vector<std::string>> &ans
) {
    if (curWord == n && curSquare == 0) {
        return build(0, curSquare + 1, n, a, used, ans);
    } else if (curWord == n && curSquare == 1) {
        return true;
    }
    for (int iWord = 0; iWord < N_SQUARES * n; iWord++) {
        if (used[iWord]) {
            continue;
        }
        bool isPossible = true;
        for (int iLetter = 0; iLetter < curWord; iLetter++) {
            if (a[iWord][iLetter] != ans[curSquare][iLetter][curWord]) {
                isPossible = false;
                break;
            }
        }
        bool canBuild = false;
        if (isPossible) {
            used[iWord] = true;
            ans[curSquare][curWord] = a[iWord];
            canBuild = build(curWord + 1, curSquare, n, a, used, ans);
            used[iWord] = false;
        }
        if (canBuild) {
            return true;
        }
    }
    return false;
}

void print(
    const std::vector<std::vector<std::string>> &ans,
    const int n
) {
    for (int iSquare = 0; iSquare < 2; iSquare++) {
        for (int iWord = 0; iWord < n; iWord++) {
            printf("%s\n", ans[iSquare][iWord].c_str());
        }
        printf("\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<std::string> a(N_SQUARES * n);
    for (int i = 0; i < N_SQUARES * n; i++) {
        char buf[1 + 10];
        scanf("%s", &buf);
        a[i] = std::string(buf);
    }
    std::vector<std::vector<std::string>> ans(N_SQUARES, std::vector<std::string>(N_SQUARES * n));
    std::vector<bool> used(N_SQUARES * n);
    for (int iWord = 0; iWord < N_SQUARES * n; iWord++) {
        used[iWord] = true;
        ans[0][0] = a[iWord];
        if (build(1, 0, n, a, used, ans)) {
            print(ans, n);
            break;
        }
        used[iWord] = false;
    }
    return 0;
}
