#include <stdio.h>
#include <vector>
#include <string>

const int n = 4;

bool build(
    int id,
    const int posI,
    const int posJ,
    const std::string &s,
    const std::vector<std::string> &a,
    std::vector<std::vector<bool>> &was
) {
    if (id == (int)s.length()) {
        return true;
    }
    if (posI < 0 || posI >= n ||
        posJ < 0 || posJ >= n ||
        was[posI][posJ] ||
        a[posI][posJ] != s[id]
        ) {
        return false;
    }
    was[posI][posJ] = true;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di * di + dj * dj != 1) {
                continue;
            }
            int newI = posI + di;
            int newJ = posJ + dj;

            if (id + 1 == (int)s.length() || 
                0 <= newI && newI < n &&
                0 <= newJ && newJ < n &&
                !was[newI][newJ] &&
                a[newI][newJ] == s[id + 1] &&
                build(id + 1, newI, newJ, s, a, was)
            ) {
                return true;
            }
        }
    }
    was[posI][posJ] = false;
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        char buf[1 + 4];
        scanf("%s", &buf);
        a[i] = std::string(buf);
    }
    int nWords;
    scanf("%d", &nWords);
    for (int iWord = 0; iWord < nWords; iWord++) {
        char buf[1 + 16];
        scanf("%s", &buf);
        std::string s(buf);
        printf("%s: ", s.c_str());
        std::vector<std::vector<bool>> was(n, std::vector<bool>(n, false));
        bool findWord = false;
        for (int i = 0; i < n && !findWord; i++) {
            for (int j = 0; j < n && !findWord; j++) {
                if (build(0, i, j, s, a, was)) {
                    findWord = true;
                }
            }
        }
        printf(findWord ? "YES\n" : "NO\n");
    }
    return 0;
}