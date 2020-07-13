#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

struct Point {

    int x;

    int y;

    static Point read() {
        int x, y;
        scanf("%d %d", &x, &y);
        return Point{ x, y };
    }

    int squareDist(Point second) {
        int dx = x - second.x;
        int dy = y - second.y;
        return dx * dx + dy * dy;
    }
};

struct Vector {

    int x;

    int y;

    Vector(Point first, Point second)
        : x(second.x - first.x)
        , y(second.y - first.y) {
    }

    int vectorProduct(Vector second) {
        return x * second.y - y * second.x;
    }
};

struct Triangle {

    Point p1;

    Point p2;

    Point p3;

    static Triangle read() {
        Point p1 = Point::read();
        Point p2 = Point::read();
        Point p3 = Point::read();
        return Triangle{ p1, p2, p3 };
    }

    void fillEdge(const int dist, std::map <int, int>& edge) {
        if (edge.find(dist) == edge.end()) {
            edge[dist] = 1;
        } else {
            edge[dist];
        }
    }

    std::map <int, int> getEdges() {
        std::map <int, int> edge;
        int d1 = p1.squareDist(p2);
        int d2 = p2.squareDist(p3);
        int d3 = p3.squareDist(p1);
        fillEdge(d1, edge);
        fillEdge(d2, edge);
        fillEdge(d3, edge);
        return edge;
    }

    int getSignedSquared() {
        int e12 = p1.squareDist(p2);
        int e23 = p2.squareDist(p3);
        int e31 = p3.squareDist(p1);
        if (e12 < e23 && e23 < e31) {
            Vector min = Vector(p1, p2);
            Vector max = Vector(p1, p3);
            return min.vectorProduct(max);
        } else if (e12 < e31 && e31 < e23) {
            Vector min = Vector(p2, p1);
            Vector max = Vector(p2, p3);
            return min.vectorProduct(max);
        } else if (e23 < e12 && e12 < e31) {
            Vector min = Vector(p3, p2);
            Vector max = Vector(p3, p1);
            return min.vectorProduct(max);
        } else if (e23 < e31 && e31 < e12) {
            Vector min = Vector(p2, p3);
            Vector max = Vector(p2, p1);
            return min.vectorProduct(max);
        } else if (e31 < e12 && e12 < e23) {
            Vector min = Vector(p3, p1);
            Vector max = Vector(p3, p2);
            return min.vectorProduct(max);
        } else if (e31 < e23 && e23 < e12) {
            Vector min = Vector(p1, p3);
            Vector max = Vector(p1, p2);
            return min.vectorProduct(max);
        } else {
            throw 1;
        }
    }

    bool canBeMovedFrom(Triangle second) {
        std::map<int, int> curEdges = this->getEdges();
        std::map<int, int> prevEdges = second.getEdges();

        for (auto item : curEdges) {
            if (prevEdges.find(item.first) == prevEdges.end()) {
                return false;
            } else if (prevEdges[item.first] != item.second) {
                return false;
            }
        }

        if (curEdges.size() < 3) {
            return true;
        }

        return this->getSignedSquared() == second.getSignedSquared();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    Triangle sample = Triangle::read();
    for (int i = 1; i < n; i++) {
        Triangle cur = Triangle::read();
        if (!sample.canBeMovedFrom(cur)) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}