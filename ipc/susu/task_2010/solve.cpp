#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

struct Board {

    int len;

    int slits = 0;

    double segment;

    bool operator<(const Board &second) const{
        return segment < second.segment;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, dist;
    scanf("%d %d", &n, &dist);
    std::priority_queue<Board> q;
    double minValue = (double)1e9;;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        minValue = std::min(minValue, (double)value);
        q.push(Board{ value, 0, 1.0 * value });
    }
    const double eps = (double)1e-6;
    int ans = 0;
    while (true) {
        Board cur = q.top();
        q.pop();
        double diff = cur.segment - minValue;
        if (std::abs(diff) < dist + eps) {
            break;
        } else {
            ans++;
            cur.slits++;
            cur.segment = 1.0 * cur.len / (cur.slits + 1);
            if (cur.segment < minValue) {
                minValue = cur.segment;
            }
            q.push(cur);
        }
    }
    printf("%d", ans);
    return 0;
}