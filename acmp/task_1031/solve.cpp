#include <stdio.h>
#include <unordered_map>
#include <string>

void read(std::string &number) {
    char c;
    while (true) {
        int code = scanf("%c", &c);
        if (code == EOF || c == '\n') {
            break;
        }
        if ('0' <= c && c <= '9') {
            number += c;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::unordered_map<std::string, int> ans;
    int counter = 0;
    for (int i = 0; i <= n; i++) {
        std::string number;
        read(number);
        if (!number.empty()) {
            ans[number]++;
            if (ans[number] == 1) {
                counter++;
            } else if (ans[number] == 6) {
                counter--;
            }
        }
    }
    printf("%d\n", counter);
    for (auto item : ans) {
        if (1 <= item.second && item.second <= 5) {
            printf("%s\n", item.first.c_str());
        }
    }
    return 0;
}