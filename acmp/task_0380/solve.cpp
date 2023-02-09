#include <stdio.h>
#include <vector>
#include <algorithm>

enum Options {
    START,
    END
};

struct Event {

    Options type;

    int coord;

    int id;

    bool operator <(const Event &second)const {
        if (coord != second.coord) {
            return coord < second.coord;
        } else {
            return type < second.type;
        }
    }
};

struct Rectangle {

    int x1;

    int y1;

    int x2;

    int y2;

    static Rectangle read() {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        return Rectangle{ std::min(x1, x2), std::min(y1, y2),
            std::max(x1, x2), std::max(y1, y2) };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<Rectangle> r(n);
    std::vector<Event> eventX(2 * n);
    for (int i = 0; i < n; i++) {
        r[i] = Rectangle::read();
        eventX[2 * i] = Event{ Options::START, r[i].x1, i };
        eventX[2 * i + 1] = Event{ Options::END, r[i].x2, i };
    }
    std::sort(eventX.begin(), eventX.end());
    std::vector<Event> eventY;
    int ans = 0;
    int nLayers = 0; 
    int sumY = 0;
    for (int iEvent = 0; iEvent < 2 * n; iEvent++) { // use DSU to O(~nlogn)
        if (iEvent > 0) {
            ans += (eventX[iEvent].coord - eventX[iEvent - 1].coord) * sumY;
        }
        if (eventX[iEvent].type == Options::START) {
            eventY.push_back(Event{Options::START, r[eventX[iEvent].id].y1, eventX[iEvent].id });
            eventY.push_back(Event{Options::END, r[eventX[iEvent].id].y2, eventX[iEvent].id });
        } else {
            for (int iEventY = 0; iEventY < (int)eventY.size(); iEventY++) {
                if (eventY[iEventY].id == eventX[iEvent].id) {
                    eventY.erase(eventY.begin() + iEventY);
                    iEventY--;
                }
            }
        }
        std::sort(eventY.begin(), eventY.end());
        sumY = 0;
        for (int iEventY = 0; iEventY < (int)eventY.size(); iEventY++) {
            if (iEventY > 0 && nLayers > 0) {
                sumY += eventY[iEventY].coord - eventY[iEventY - 1].coord;
            }
            if (eventY[iEventY].type == Options::START) {
                nLayers++;
            } else {
                nLayers--;
            }
        }
    }
    printf("%d", ans);
    return 0;
}