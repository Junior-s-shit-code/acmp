#include <stdio.h>
#include <vector>
#include <string>
#include <climits>

struct Man {

    std::string name;

    int time;

    static Man read(int nCircles) {
        char buf[1 + 255];
        scanf("%s", &buf);
        int sum = 0;
        for (int i = 0; i < nCircles; i++) {
            int time;
            scanf("%d", &time);
            sum += time;
        }
        return Man{ std::string(buf), sum };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nMen, nCircles;
    scanf("%d %d", &nMen, &nCircles);
    std::vector<Man> a(nMen);
    std::string ans = "";
    int minTime = INT_MAX;
    for (int i = 0; i < nMen; i++) {
        a[i] = Man::read(nCircles);
        if (a[i].time < minTime) {
            minTime = a[i].time;
            ans = a[i].name;
        }
    }
    printf("%s", ans.c_str());
    return 0;
}