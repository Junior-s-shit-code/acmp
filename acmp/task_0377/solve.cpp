#include <stdio.h>
#include <vector>
#include <algorithm>

struct Segment {

    int left;

    int right;

    static Segment read() {
        int left, right;
        scanf("%d %d", &left, &right);
        return Segment{ left, right };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector <Segment> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = Segment::read();
    }
    std::sort(a.begin(), a.end(), [](const Segment& first, const Segment& second) {
        if (first.left == second.left) {
            return first.right > second.right;
        }
        return first.left < second.left;
    });

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < n - 1 && a[i + 1].left <= a[i].right) {
            a[i + 1] = Segment{ a[i].left, std::max(a[i].right, a[i + 1].right) };
        } else {
            ans += a[i].right - a[i].left;
        } 
    }
    printf("%d", ans);
    return 0;
}