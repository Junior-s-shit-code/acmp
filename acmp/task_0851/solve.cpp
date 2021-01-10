#include <stdio.h>
#include <algorithm>
#include <string>

std::string ans(int boys, int girls) {
    std::string s = "";
    while (boys >= 1 && girls >= 2) {
        s += "BGG";
        boys--;
        girls -= 2;
    }
    return std::string(girls, 'G') + s + std::string(boys, 'B');
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nBoys, nGirls;
    scanf("%d %d", &nBoys, &nGirls);
    printf("%s", ans(nBoys, nGirls).c_str());
    return 0;
}