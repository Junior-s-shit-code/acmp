#include <stdio.h>
#include <vector>
#include <algorithm>

int getTime() {
    int h, m;
    scanf("%d:%d", &h, &m);
    return h * 60 + m;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const long long MAX_TIME = 24 * 60;
    int n;
    scanf("%d", &n);
    std::vector<int> in(MAX_TIME, 0);
    std::vector<int> out(MAX_TIME, 0);
    for (int i = 0; i < n; i++) {
        in[getTime()]++;
        out[getTime()]++;
    }
    int maxVisitors = 0;
    int curVisitors = 0;
    for (int i = 0; i < MAX_TIME; i++) {
        curVisitors += in[i];
        maxVisitors = std::max(maxVisitors, curVisitors);
        curVisitors -= out[i];
    }
    printf("%d", maxVisitors);
    return 0;
} 