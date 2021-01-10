#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <utility>

bool isValid(const std::string &str) {
    if (str[0] != '<' || str.back() != '>') {
        return false;
    }
    std::stack<std::string> open;
    int i = 0;
    while (true) {
        if (i == (int)str.size()) {
            break;
        }
        if (str[i] != '<') {
            return false;
        }
        i++;
        bool closing = false;
        if (str[i] == '/') {
            closing = true;
            i++;
        }
        if (!('a' <= str[i] && str[i] <= 'z')) {
            return false;
        }
        std::string tag(1, str[i]);
        i++;
        while ('a' <= str[i] && str[i] <= 'z') {
            tag.push_back(str[i]);
            i++;
        }
        if (str[i] != '>') {
            return false;
        }
        i++;
        if (!closing) {
            open.push(std::move(tag));
        } else {
            if (open.empty()) {
                return false;
            }
            if (open.top() != tag) {
                return false;
            }
            open.pop();
        }
    }
    return open.empty();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char buf[1 + 1000];
    scanf("%s", &buf);
    std::string str(buf);
    std::string chars = "</>";
    for (int c = 'a'; c <= 'z'; c++) {
        chars += c;
    }
    for (char &c : str) {
        char oldC = c;
        for (char newC : chars) {
            if (newC != oldC) {
                c = newC;

                if (isValid(str)) {
                    printf("%s", str.c_str());
                    return 0;
                }
            }
        }
        c = oldC;
    }
    return 0;
}