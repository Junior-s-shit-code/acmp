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

std::vector<int> parent;
std::vector<int> rank;

void makeSet(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int findSet(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b, int &counter) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        counter--;
        if (rank[a] < rank[b]) {
            std::swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    parent = rank = std::vector<int>(n, -1);
    rank = std::vector<int>(n, -1);
    std::vector<Rect> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = Rect::read();
        makeSet(i);
    }
    int counter = n;
    for (int v = 0; v < n; v++) {
        for (int v2 = 0; v2 < n; v2++) {
            if (v == v2) {
                continue;
            }
            if (r[v].intersect(r[v2]) || r[v2].intersect(r[v])) {
                unionSets(v, v2, counter);
            }
        }
    }

    printf("%d", counter);
    return 0;
}