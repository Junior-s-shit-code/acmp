#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

struct Problem {

    int timeBegin;

    int timeLen;

    int cost;

    int prev;

    long long ans;
};

struct Event {

    int time;

    int id;

    int type;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<Problem> problems(n);
    std::vector<Event> events(2 * n);
    for (int i = 0; i < n; i++) {
        int timeBegin, timeLen, cost;
        scanf("%d %d %d", &timeBegin, &timeLen, &cost);
        problems[i] = Problem{ timeBegin, timeLen, cost };
        events[i * 2] = Event{ timeBegin, i, 1 };
        events[i * 2 + 1] = Event{ timeBegin + timeLen, i , -1 };
    }
    std::sort(events.begin(), events.end(), [](const Event &left, const Event &right) {
        if (left.time != right.time) {
            return left.time < right.time;
        }
        return left.type < right.type;
    });
    long long maxSum = 0;
    int pId = -1;
    for (Event curEvent : events) {
        if (curEvent.type == 1) {
            problems[curEvent.id].ans = maxSum + problems[curEvent.id].cost;
            problems[curEvent.id].prev = pId;
        } else if (maxSum < problems[curEvent.id].ans) {
            maxSum = problems[curEvent.id].ans;
            pId = curEvent.id;
        }
    }

    std::vector<int> ans;
    while (pId != -1) {
        ans.push_back(pId);
        pId = problems[pId].prev;
    }
    std::reverse(ans.begin(), ans.end());
    printf("%lld\n%d\n", maxSum, (int)ans.size());
    for (int answer : ans) {
        printf("%d ", answer + 1);
    }
    return 0;
}