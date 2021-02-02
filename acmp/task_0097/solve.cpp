#include <stdio.h>
#include <algorithm>
#include <vector>

struct Point {

    int x;

    int y;

    static Point read() {
        int x, y;
        scanf("%d %d", &x, &y);
        return Point{ x, y };
    }

    static void formatPoints(Point &p1, Point &p2, int extra) {
        int x1 = p1.x;
        int x2 = p2.x;
        int y1 = p1.y;
        int y2 = p2.y;
        p1 = Point{ std::min(x1, x2) - extra, std::min(y1, y2) - extra };
        p2 = Point{ std::max(x1, x2) + extra, std::max(y1, y2) + extra };
    }
};

struct Rect {

    int x1;

    int x2;

    int y1;

    int y2;

    static Rect read() {
        Point p1 = Point::read();
        Point p2 = Point::read();
        int extra;
        scanf("%d", &extra);
        Point::formatPoints(p1, p2, extra);
        return Rect{ p1.x, p2.x, p1.y, p2.y };
    }

    bool intersect(const Rect &r) const {
        return !(x2 < r.x1 || r.x2 < x1 || y2 < r.y1 || r.y2 < y1);
    }
};

void dsuMake(
    int v,
    std::vector<int> &parent,
    std::vector<int> &rank
) {
    parent[v] = v;
    rank[v] = 0;
}

int dsuGet(
    int v,
    std::vector<int> &parent,
    std::vector<int> &rank
) {
    while (v != parent[v]) {
        v = parent[v];
    }
    return v;
}

bool dsuUnion(
    int a,
    int b,
    std::vector<int> &parent,
    std::vector<int> &rank
) {
    a = dsuGet(a, parent, rank);
    b = dsuGet(b, parent, rank);
    if (a != b) {
        if (rank[a] < rank[b]) {
            std::swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
        return true;
    }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<int> parent(n, -1);
    std::vector<int> rank(n, -1);
    std::vector<Rect> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = Rect::read();
        dsuMake(i, parent, rank);
    }
    int nComponents = n;
    for (int v1 = 0; v1 < n; v1++) {
        for (int v2 = v1 + 1; v2 < n; v2++) {
            if ((r[v1].intersect(r[v2]) || r[v2].intersect(r[v1])) && dsuUnion(v1, v2, parent, rank)) {
                nComponents--;
            }
        }
    }

    printf("%d", nComponents);
    return 0;
}