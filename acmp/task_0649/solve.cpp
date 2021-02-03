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
    std::string str(buf);
    std::unordered_map<char, int> equal;
    long long ans = 0;
    int right = -1;
    for (int left = 0; left < n; left++) {
        while (right + 1 < n && equal[str[right + 1]] < maxEqual) {
            right++;
            equal[str[right]]++;
        }
        ans += (long long) right - left + 1;
        equal[str[left]]--;
    }
    printf("%lld", ans);
    return 0;
}