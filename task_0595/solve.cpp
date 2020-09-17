#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> getPrefixFunction(std::string &str) {
    int n = (int)str.length();
    std::vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && str[i] != str[j]) {
            j = p[j - 1];
        }
        if (str[i] == str[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char buf[1 + 50000];
    scanf("%s", &buf);
    std::string str(buf);
    scanf("%s", &buf);
    std::string sample(buf);
    std::string string = sample + "#" + str;
    std::vector<int> p = getPrefixFunction(string);
    int rightLen = p[(int)p.size() - 1];
    std::string toEqual = str.substr((int)str.length() - rightLen, rightLen);
    std::string toReverse = str.substr(0, (int)str.length() - rightLen);
    std::reverse(toReverse.begin(), toReverse.end());
    std::string ans = toEqual + toReverse;
    if (ans == sample) {
        printf("Yes\n%d", (int)toReverse.size());
    } else {
        printf("No");
    }
    return 0;
}