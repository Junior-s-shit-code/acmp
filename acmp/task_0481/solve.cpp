#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char buf[1+30];
    scanf("%s", &buf);
    std::string s(buf);
    int n = (int)s.length();
    std::vector<std::vector<int>> a(n, std::vector<int> (n, 0));
    for (int len = 1; len <= n; len++) { 
        for (int startPos = 0; startPos + len <= n; startPos++) {
            int endPos = startPos + len - 1;
            if (len == 1) {
                a[startPos][endPos] = 1;
                continue;
            }
            int left = std::min(startPos + 1, endPos);
            int right = std::max(startPos, endPos - 1);
            
            if (s[startPos] != s[endPos]) {
                a[startPos][endPos] = a[startPos][right] + a[left][endPos] - a[left][right];
            } else if (s[startPos] == s[endPos]) {
                a[startPos][endPos] = a[startPos][right] + a[left][endPos] + 1;
            }
        }
    }
    printf("%d", a[0][n - 1]);
    return 0;
}