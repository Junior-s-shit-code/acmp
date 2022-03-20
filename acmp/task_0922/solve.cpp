#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tFly, tCharge;
    int sFly, sCharge;
    int dist;
    scanf("%d %d %d %d %d", &tFly, &tCharge, &sFly, &sCharge, &dist);
    int distDiff = sFly - sCharge;
    if (dist <= sFly) {
        printf("%.2lf", 1.0 * dist / sFly * tFly);
    } else if (distDiff <= 0) {
        printf("NO");
    } else {
        int cycleTime = tFly + tCharge;
        int nCycles = (dist - sFly + distDiff - 1) / distDiff;
        double time = 1LL * nCycles * cycleTime + ((1.0 * dist - 1LL * distDiff * nCycles) / sFly) * tFly;
        printf("%.2lf", time);
    }
    return 0;
}