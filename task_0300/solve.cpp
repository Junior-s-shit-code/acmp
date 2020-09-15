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
    std::vector <Rocket> r(4);
    long long FACTOR = 1;
    for (int i = 0; i < 4; i++) {
        r[i] = Rocket::read(i);
        FACTOR *= r[i].speed;
    }
    long long moveTime, dist;
    scanf("%lld %lld", &moveTime, &dist);
    moveTime *= FACTOR;
    dist *= FACTOR;
    for (int i = 0; i < 4; i++) {
        r[i].startTime *= FACTOR;
    }

    for (int i = 0; i < 4; i++) {
        r[i].impactTime = r[i].startTime + dist / r[i].speed;;
    }

    std::sort(r.begin(), r.end(), [](const Rocket &left, const Rocket &right) {
        return left.impactTime < right.impactTime;
    });
    for (int i = 1; i < 4; i++) {
        long long diff = r[i].impactTime - r[i - 1].impactTime;
        int k = ((r[i].id & 1) == (r[i - 1].id & 1)) ? 2 : 1;
        if (diff < moveTime * k) {
            if (i < 3 && k == 2 && r[i].impactTime == r[i + 1].impactTime && diff >= moveTime) {
                i++;
            }
            printf("%d", i);
            return 0;
        }
    }
    printf("ALIVE");
    return 0;
}