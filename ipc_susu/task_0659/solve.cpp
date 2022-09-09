#include <stdio.h>
#include <map>
#include <string>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::map<int, int> cost;
    cost[0] = 6;
    cost[1] = 2;
    cost[2] = 5;
    cost[3] = 5;
    cost[4] = 4;
    cost[5] = 5;
    cost[6] = 6;
    cost[7] = 3;
    cost[8] = 7;
    cost[9] = 6;
    char buf[1 + 10];
    scanf("%s", &buf);
    std::string s(buf);
    int count = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        count += cost[s[i] - '0'];
    }
    printf("%d", count);
    return 0;
}