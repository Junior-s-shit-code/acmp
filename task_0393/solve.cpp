#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cassert>

struct Song {

    int time;

    int index;

};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::unordered_map <std::string, Song> mp;
    std::vector <int> ans(n);
    for (int i = 0; i < n; i++) {
        char buf[1 + 50];
        int time;
        scanf("%s %d", &buf, &time);
        mp[std::string(buf)] = Song{ time, i };
    }
    int nPlays, nSkip;
    scanf("%d %d", &nPlays, &nSkip);
    std::vector <std::string> q(nPlays);
    for (int i = 0; i < nPlays; i++) {
        char buf[1+50];
        scanf("%s", &buf);
        q[i] = std::string(buf);
    }
    const int INF = 1000000000;
    std::vector <int> skip(nSkip + 1, INF);
    for (int i = 0; i < nSkip; i++) {
        scanf("%d", &skip[i]);
    }

    int curTime = 0;
    int skipIndex = 0;
    for (int i = 0; i < nPlays; i++) {
        curTime += mp[q[i]].time;
        if (skip[skipIndex] < curTime) {
            ans[mp[q[i]].index]--;
            curTime = skip[skipIndex];
            skipIndex++;
        } else if (skip[skipIndex] == curTime) {
            assert(i < nPlays - 1); //if we skip non-existent song
            ans[mp[q[i]].index]++;
            ans[mp[q[i + 1]].index]--;
            curTime = skip[skipIndex];
            skipIndex++;
            i++;
        } else {
            ans[mp[q[i]].index]++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}