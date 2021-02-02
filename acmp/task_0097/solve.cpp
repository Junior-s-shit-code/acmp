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

class DSU {

private:

    std::vector<int> parent;

    std::vector<int> rank;

public:

    DSU(const int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int getSets(int v) {
        while (v != parent[v]) {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        return v;
    }

    bool unionSets(int a, int b) {
        a = getSets(a);
        b = getSets(b);
        if (a == b) {
            return false;
        }
        if (rank[a] < rank[b]) {
            std::swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
        return true;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    DSU dsu(n);
    std::vector<Rect> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = Rect::read();
    }
    int nComponents = n;
    for (int v1 = 0; v1 < n; v1++) {
        for (int v2 = v1 + 1; v2 < n; v2++) {
            if (r[v1].intersect(r[v2]) && dsu.unionSets(v1, v2)) {
                nComponents--;
            }
        }
    }

    printf("%d", nComponents);
    return 0;
}