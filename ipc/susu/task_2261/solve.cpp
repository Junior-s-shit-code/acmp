#include <stdio.h>
#include <vector>
#include <algorithm>

struct Point {

    int i;

    int j;
};

struct Router {

    int iRow;

    int iColumn;

    Point leftTop;

    Point rightBot;

    static Router read() {
        int iRow, iColumn;
        scanf("%d %d", &iRow, &iColumn);
        return Router{ iRow, iColumn, Point {0, 0}, Point {0, 0} };
    }
};

struct Event {

    int j;

    int type;

    int iRouter;
};

long long getPriority(
    int dist,
    const int sizeI,
    const int sizeJ,
    const int nRouters,
    std::vector<Router> &routers
) {
    std::vector<int> iLine(2 * nRouters);
    std::vector<Event> events(2 * nRouters);
    for (int iR = 0; iR < nRouters; iR++) {
        routers[iR].leftTop = Point{
            std::max(0, routers[iR].iRow - dist - 1),
            std::max(0, routers[iR].iColumn - dist - 1)
        };
        routers[iR].rightBot = Point{
            std::min(sizeI, routers[iR].iRow + dist),
            std::min(sizeJ, routers[iR].iColumn + dist)
        };
        iLine[iR * 2] = routers[iR].leftTop.i;
        iLine[iR * 2 + 1] = routers[iR].rightBot.i;
        events[iR * 2] = Event{ routers[iR].leftTop.j, 1, iR };
        events[iR * 2 + 1] = Event{ routers[iR].rightBot.j, -1, iR };
    }
    std::sort(iLine.begin(), iLine.end());
    std::sort(events.begin(), events.end(), [](const Event &left, const Event &right) {
        if (left.j != right.j) {
            return left.j < right.j;
        }
        return left.type < right.type;
    });
    long long commonSquare = 0;
    for (int i = 0; i + 1 < 2 * nRouters; i++) {
        if (iLine[i] != iLine[i + 1]) {
            int countRouters = 0;
            for (int iEvent = 0; iEvent + 1 < 2 * nRouters; iEvent++) {
                if (routers[events[iEvent].iRouter].leftTop.i <= iLine[i] &&
                    iLine[i + 1] <= routers[events[iEvent].iRouter].rightBot.i
                    ) {
                    countRouters += events[iEvent].type;
                }
                if (events[iEvent].j < events[iEvent + 1].j && countRouters > 0) {
                    long long curSquare = 1LL * events[iEvent + 1].j - events[iEvent].j;
                    curSquare *= 1LL * iLine[i + 1] - iLine[i];
                    commonSquare += curSquare;
                }
            }
        }
    }
    return commonSquare - nRouters;
}

long long getDist(
    long long needPriority,
    const int sizeI,
    const int sizeJ,
    const int nRouters,
    std::vector<Router> &routers
) {
    int left = 0;
    int right = (int)1e9 + 1;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (getPriority(mid, sizeI, sizeJ, nRouters, routers) >= needPriority) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int sizeI, sizeJ, nRouters, nQ;
    scanf("%d %d %d %d", &sizeI, &sizeJ, &nRouters, &nQ);
    std::vector<Router> routers(nRouters);
    for (int i = 0; i < nRouters; i++) {
        routers[i] = Router::read();
    }
    for (int q = 0; q < nQ; q++) {
        long long wantedPriority;
        scanf("%lld", &wantedPriority);
        printf("%lld\n", getDist(wantedPriority, sizeI, sizeJ, nRouters, routers));
    }
    return 0;
}