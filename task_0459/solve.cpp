#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

struct Point {

    int i;

    int j;

    bool operator<(const Point second)const {
        if (i == second.i) {
            return j < second.j;
        }
        return i < second.i;
    }

    bool operator==(const Point second)const {
        return (i == second.i && j == second.j);
    }

    Point nextPoint(char way)const {
        if (way == 'N') {
            return Point{ i - 1, j };
        } else if (way == 'S') {
            return Point{ i + 1, j };
        } else if (way == 'W') {
            return Point{ i, j - 1 };
        } else if (way == 'E') {
            return Point{ i, j + 1 };
        } else {
            throw 1;
        }
    }

    Point getBridge(char way) const {
        return this->nextPoint(way);
    }

    Point getPoint(char way) const {
        Point p = this->nextPoint(way);
        p = p.nextPoint(way);
        return p;
    }
};

template<>
struct std::hash<Point> {
    std::size_t operator()(const Point &p) const {
        std::size_t res = 17;
        res = res * 31 + std::hash<int>()(p.i);
        res = res * 31 + std::hash<int>()(p.j);
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int INF = (int)1e9;
    char buf[1 + 200];
    scanf("%s", &buf);
    std::string str(buf);
    std::unordered_set<Point> set;
    Point prev = Point{ 0, 0 };
    set.insert(prev);
    std::unordered_map<Point, int> len;
    for (int i = 0; i < (int)str.length(); i++) {
        Point bridge = prev.getBridge(str[i]);
        Point cur = prev.getPoint(str[i]);
        set.insert(bridge);
        set.insert(cur);
        len[cur] = INF;
        prev = cur;
    }

    std::vector<char> nameOfWays = { 'N', 'E', 'S', 'W' };
    std::queue <Point> q;
    q.push(Point{ 0, 0 });
    len[Point{ 0, 0 }] = 0;
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (char way : nameOfWays) {
            Point p2 = cur.getPoint(way);
            if (set.find(cur.getBridge(way)) != set.end() && len[p2] > len[cur] + 1) {
                len[p2] = len[cur] + 1;
                q.push(p2);
            }
        }
    }

    Point p = prev;
    while (!(p.i == 0 && p.j == 0)) {
        for (char way : nameOfWays) {
            if (set.find(p.getBridge(way)) == set.end()) {
                continue;
            }
            Point p2 = p.getPoint(way);
            if (len[p2] < len[p]) {
                p = p2;
                printf("%c", way);
                break;
            }
        }
    }
    return 0;
}