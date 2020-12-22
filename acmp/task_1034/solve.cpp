#include <stdio.h>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MAX_SPEED = 1000;
    int greenTime, redTime, dist;
    scanf("%d %d %d", &greenTime, &redTime, &dist);
    double minTime = 1.0 * dist / MAX_SPEED;
    double extraTime = std::fmod(minTime, greenTime + redTime); // extra time to drive at maximum speed
    if (extraTime <= greenTime || extraTime >= redTime) {
        printf("%d", MAX_SPEED);
    } else {
        double actualTime = minTime + redTime - extraTime;
        printf("%.9lf", 1.0 * dist / actualTime);
    }
    return 0;
}