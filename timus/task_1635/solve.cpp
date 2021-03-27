#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

void update(
    int id,
    const int parity,
    const int len,
    const std::string &s,
    std::vector<int> &count,
    std::vector<int> &curLen
) {
    int left = id;
    int right = id + parity;
    while (0 < left && right <= len) {
        if (s[left] != s[right]) {
            break;
        }
        if (count[left - 1] + 1 < count[right]) {
            count[right] = count[left - 1] + 1;
            curLen[right] = right - left + 1;
        }
        left--;
        right++;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int INF = 5000;
    char buf[1 + 4000];
    scanf("%s", &buf);
    std::string s = '#' + std::string(buf);
    int len = (int)s.length() - 1;

    std::vector<int> count(len + 1, INF);
    std::vector<int> curLen(len + 1, INF);
    count[0] = 0;

    for (int i = 1; i <= len; i++) {
        update(i, 0, len, s, count, curLen); 
        update(i, 1, len, s, count, curLen); 
    }

    printf("%d\n", count[len]);
    int right = len;
    std::vector<std::string> ans;
    while (right > 0) {
        int left = right - curLen[right] + 1;
        ans.push_back(s.substr(left, curLen[right]));
        right = left - 1;
    }
    std::reverse(ans.begin(), ans.end());
    for (const std::string &item : ans) {
        printf("%s ", item.c_str());
    }
    return 0;
}