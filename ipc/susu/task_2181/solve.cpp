#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

std::string toBin(int num) {
    std::string str = "";
    while (num) {
        str.insert(str.begin(), (num & 1) + '0');
        num >>= 1;
    }
    return str;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if (a < b) {
        std::swap(a, b);
    }
    std::string str1 = toBin(a);
    std::string str2 = toBin(b);
    while ((int)str2.length() < (int)str1.length()) {
        str2.insert(str2.begin(), '0');
    }
    int ans = -1;
    bool isTwo = false;
    for (int i = 0; i < (int)str1.length(); i++) {
        int value = str1[i] + str2[i] - 2 * '0';
        if (value > 0) {
            ans = i;
        }
    }
    printf("%d", ans + 1);
    return 0;
}