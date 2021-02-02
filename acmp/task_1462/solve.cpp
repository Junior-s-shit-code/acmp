#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

struct Rect {

    int x;

    int y;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, need;
    scanf("%d %d", &n, &need);
    std::vector<Rect> rects(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &rects[i].x, &rects[i].y);
    }
    std::sort(rects.begin(), rects.end(), [](const Rect &left, const Rect &right) {
        return left.y > right.y;
    });
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    long long ans = 0;
    for (const Rect &r : rects) {
        q.push(r.x);
        if ((int) q.size() > need) {
            q.pop();
        }
        if ((int) q.size() == need) {
            ans = std::max(ans, 1LL * r.y * q.top());
        }
    }
    printf("%lld", ans);
    return 0;
}