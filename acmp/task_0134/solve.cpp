#include <stdio.h>
#include <vector>
#include <queue>

struct Way {

    int to;

    int timeStart;

    int timeEnd;

    static Way read() {
        int to, t1, t2;
        scanf("%d %d %d", &t1, &to, &t2);
        return Way{ to, t1, t2 };
    }
};

struct City {

    int id;

    int timeIn;

    bool operator<(const City &second) const{
        if (timeIn != second.timeIn) {
            return timeIn > second.timeIn;
        }
        return id > second.id;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, start, end;
    scanf("%d %d %d", &n, &start, &end);
    int nBus;
    scanf("%d", &nBus);
    std::vector<std::vector<Way>> ways(n + 1);
    for (int i = 0; i < nBus; i++) {
        int from;
        scanf("%d", &from);
        ways[from].push_back(Way::read());
    }
    const int INF = (int)1e9;
    std::vector<int> time(n + 1, INF);
    time[start] = 0;
    std::priority_queue<City> q;
    q.push(City{ start, 0 });
    while (!q.empty()) {
        City cur = q.top();
        q.pop();

        if (cur.timeIn == INF) {
            break;
        }

        for (const Way &way : ways[cur.id]) {
            if (cur.timeIn <= way.timeStart && way.timeEnd < time[way.to]) {
                time[way.to] = way.timeEnd;
                q.push(City{ way.to, way.timeEnd });

            }
        }
    }
    printf("%d", time[end] == INF ? -1 : time[end]);
    return 0;
}