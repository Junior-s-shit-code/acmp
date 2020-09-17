#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

struct Rocket {

    int id;

    long long startTime;

    long long speed;

    long long impactTime;

    static Rocket read(const int id) {
        long long startTime, speed;
        scanf("%lld %lld", &startTime, &speed);
        return Rocket{ id, startTime, speed, 0 };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::vector <Rocket> rocket(4);
    long long speedProd = 1;
    for (int i = 0; i < 4; i++) {
        rocket[i] = Rocket::read(i);
        speedProd *= rocket[i].speed;
    }
    long long moveTime, dist;
    scanf("%lld %lld", &moveTime, &dist);
    moveTime *= speedProd;
    dist *= speedProd;
    for (int i = 0; i < 4; i++) {
        rocket[i].startTime *= speedProd;
    }

    for (int i = 0; i < 4; i++) {
        rocket[i].impactTime = rocket[i].startTime + dist / rocket[i].speed;;
    }

    std::sort(rocket.begin(), rocket.end(), [](const Rocket &left, const Rocket &right) {
        return left.impactTime < right.impactTime;
    });
    for (int i = 1; i < 4; i++) {
        long long diff = rocket[i].impactTime - rocket[i - 1].impactTime;
        int nMoves = ((rocket[i].id & 1) == (rocket[i - 1].id & 1)) ? 2 : 1;
        if (diff < moveTime * nMoves) {
            if (i < 3 && nMoves == 2 && rocket[i].impactTime == rocket[i + 1].impactTime && diff >= moveTime) {
                i++;
            }
            printf("%d", i);
            return 0;
        }
    }
    printf("ALIVE");
    return 0;
}