#include <stdio.h>
#include <string>
#include <unordered_map>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::unordered_map<char, int> buttonNumber;
    std::unordered_map<char, int> clicks;
    for (int button = 0; button < 9; button++) {
        char buf[1 + 30];
        scanf("%s", &buf);
        std::string str(buf);
        for (int i = 0; i < (int)str.length(); i++) {
            char curLow = str[i];
            buttonNumber[curLow] = button;
            clicks[curLow] = i + 1;
        }
    }
    char c;
    int prevNumber = -1;
    int ans = 0;
    bool wasSign = true;
    bool isUpper = false;
    scanf("%c", &c); // read \n before text
    while (true) {
        int code = scanf("%c", &c);
        if (code == EOF || c == '\n') {
            break;
        }
        if (c == ' ') {
            ans++;
            prevNumber = -1;
            continue;
        } else if (c == '.' || c == '?' || c == '!') {
            if (!isUpper) {
                wasSign = true;
            }
        } else if ('a' <= c && c <= 'z') {
            if (wasSign || isUpper) {
                wasSign = false;
                isUpper = false;
                ans++;
            }
        } else if ('A' <= c && c <= 'Z') {
            if (wasSign) {
                wasSign = false;
            } else if (!isUpper && !wasSign) {
                isUpper = true;
                ans++;
            }
            c = c - 'A' + 'a';
        }

        if (prevNumber == buttonNumber[c]) {
            ans++;
        }
        ans += clicks[c];
        prevNumber = buttonNumber[c];
    }
    printf("%d", ans);
    return 0;
}