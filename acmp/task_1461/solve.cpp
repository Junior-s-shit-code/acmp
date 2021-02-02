#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

enum Options {
    ANNIHILATION,
    PRINT
};

struct Event {

    int time;

    Options type;
};

struct Info {

    int x;

    bool goLeft;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<Info> p(n);
    for (int i = 0; i < n; i++) {
        int x, value;
        scanf("%d %d", &x, &value);
        p[i] = Info{ x, value == -1 };
    }
    std::sort(p.begin(), p.end(), [](const Info &left, const Info &right) {
        if (left.x != right.x) {
            return left.x < right.x;
        }
        return left.goLeft < right.goLeft;
    });
    int nT;
    scanf("%d", &nT);
    std::vector<Event> events;
    events.reserve(n / 2 + nT);
    for (int i = 0; i < nT; i++) {
        int time;
        scanf("%d", &time);
        events.push_back(Event{ time, PRINT });
    }
    {
        std::stack<Info> st;
        for (int i = 0; i < n; i++) {
            if (!st.empty() && !st.top().goLeft && p[i].goLeft) {
                int timeToAnnihilate = p[i].x - st.top().x;
                events.push_back(Event{ (timeToAnnihilate + 1) / 2, ANNIHILATION });
                st.pop();
            } else {
                st.push(p[i]);
            }
        }
    }
    std::sort(events.begin(), events.end(), [](const Event &left, const Event &right) {
        if (left.time != right.time) {
            return left.time < right.time;
        }
        return left.type < right.type;
    });
    int nCorpuscles = n;
    for (int i = 0; i < (int)events.size(); i++) {
        if (events[i].type == PRINT) {
            printf("%d\n", nCorpuscles);
        } else {
            nCorpuscles -= 2;
        }
    }
    return 0;
}