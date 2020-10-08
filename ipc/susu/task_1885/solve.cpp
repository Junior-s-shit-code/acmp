#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MOD = (int)1e9 + 9;
    char buf[1 + 100];
    scanf("%s", &buf);
    std::string str(buf);
    int n = (int)str.length();
    std::vector<int> ans(n + 1, 0); 
    ans[0] = ans[1] = 1;
    for (int len = 2; len <= n; len++) {
        std::string rStr = "";
        for (int palindromLen = 1; palindromLen <= len; palindromLen++) {
            rStr += str[len - palindromLen];
            if (rStr == str.substr(len - palindromLen, palindromLen)) {
                ans[len] += ans[len - palindromLen];
                ans[len] %= MOD;
            }
        }
    }
    printf("%d", ans[n]);
    return 0;
}