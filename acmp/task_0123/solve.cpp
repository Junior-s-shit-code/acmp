#include <stdio.h>
#include <vector>
#include <string>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char buf[1 + 80];
    scanf("%s", &buf);
    std::string s(buf);
    int n = (int)s.length();
    s = '#' + s;
    std::vector<std::vector<int>> count(1 + n, std::vector<int> (1 + n, 0)); // count[len][open]
    count[0][0] = 1;
    for (int len = 1; len <= n; len++) {
        for (int open = 0; open <= n; open++) {
            if (open - 1 >= 0 && (s[len] == '?' || s[len] == '(')) {
                count[len][open] += count[len - 1][open - 1];
            }
            if (open + 1 <= n && (s[len] == '?' || s[len] == ')')) {
                count[len][open] += count[len - 1][open + 1];
            }
        }
    }
    printf("%d", count[n][0]);
    return 0;
}