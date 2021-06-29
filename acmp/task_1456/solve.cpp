#include <stdio.h>

long long getBlockId (
    long long room,
    const long long kExtra,
    const long long x,
    const long long roomsPerEntrance,
    const long long roomsPerBlock
) {
    room %= roomsPerEntrance;
    long long block = room / roomsPerBlock;
    room %= roomsPerBlock;
    long long floor = room / x;
    if (floor > kExtra - 1) {
        floor = kExtra - 1;
    }
    return block * kExtra + floor + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long nFloors, kExtra, xExtra, x;
    scanf("%lld %lld %lld %lld", &nFloors, &kExtra, &xExtra, &x);
    long long roomsPerEntrance = (nFloors / kExtra) * xExtra + (nFloors - nFloors / kExtra) * x;
    long long roomsPerBlock = (kExtra - 1) * x + xExtra;
    int nQ;
    scanf("%d", &nQ);
    for (int i = 0; i < nQ; i++) {
        long long room;
        scanf("%lld", &room);
        long long ans = getBlockId(room - 1, kExtra, x, roomsPerEntrance, roomsPerBlock);
        printf("%lld\n", ans);
    }
    return 0;
}