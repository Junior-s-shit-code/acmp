#include <stdio.h>
#include <string>
#include <unordered_map>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, maxEqual;
    scanf("%d %d", &n, &maxEqual);
    char buf[1 + (int)1e6];
    scanf("%s", &buf);
    std::string s(buf);
    std::unordered_map<char, int> equal;
    long long ans = 0;
    int right = -1;
    for (int left = 0; left < n; left++) {
        while (right + 1 < n && equal[s[right + 1]] < maxEqual) {
            right++;
            equal[s[right]]++;
        }
        ans += right - left + 1;
        equal[s[left]]--;
    }
    printf("%lld", ans);
    return 0;
}