#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

void addWords(const int k, std::unordered_map <std::string, int>& mp, const std::vector <int> abc) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        std::vector <int> a = abc;
        char buf[1 + 100];
        scanf("%s", &buf);
        std::string str(buf);
        bool isWord = true;
        for (int j = 0; j < (int)str.length(); j++) {
            int id = str[j] - 'a';
            a[id]--;
            if (a[id] < 0) {
                isWord = false;
                break;
            }
        }
        if (isWord) {
            mp[str] += k;
        }
    }
}

void solve(int first, int second, int common) {
    int ans;
    if (first + (common + 1) / 2 > second + common / 2) {
        ans = 1;
    } else if (first + (common + 1) / 2 == second + common / 2) {
        ans = 0;
    } else {
        ans = 2;
    }
    printf("%d\n", ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::vector <int> abc(26, 0);
    char c;
    while (true) {
        scanf("%c", &c);
        if (!('a' <= c && c <= 'z')) {
            break;
        }
        abc[c - 'a']++;
    }
    std::unordered_map <std::string, int> mp;
    addWords(1, mp, abc);
    addWords(-1, mp, abc);
    int first = 0, second = 0, common = 0;

    for (auto item : mp) {
        if (item.second == 1) {
            first++;
        } else if (item.second == -1) {
            second++;
        } else {
            common++;
        }
    }

    //all strategies are optimal
    solve(first, second, common);

    //first - lose, second - optimal
    int min = std::min(first, common);
    first -= min;
    common -= min;

    solve(first, second, common);

    first += min;
    common += min;

    //first - win, second - lose
    min = std::min(second, common);
    second -= min;
    common -= min;

    solve(first, second, common);

    second += min;
    common += min;
    
    return 0;
}