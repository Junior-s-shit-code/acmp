#include <stdio.h>

int binSearch(
    long long value,
    long long nFloors,
    long long kExtra,
    long long xExtra,
    long long x
) {
    int left = 1;
    int right = (int) nFloors;
    while (left < right) {
        int mid = (left + right) >> 1;
        long long maxFlat = mid * x + (xExtra - x) * (mid / kExtra);
        long long minFlat = maxFlat + 1;
        if (mid % kExtra == 0) {
            minFlat -= xExtra;
        } else {
            minFlat -= x;
        }
        if (value > maxFlat) {
            left = mid + 1;
        } else if (value < minFlat) {
            right = mid;
        } else {
            return mid;
        }
    }
    return left;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long nFloors, kExtra, xExtra, x;
    scanf("%lld %lld %lld %lld", &nFloors, &kExtra, &xExtra, &x);
    long long flatsInHouse = nFloors * x + (xExtra - x) * (nFloors / kExtra);
    int nQ;
    scanf("%d", &nQ);
    for (int q = 0; q < nQ; q++) {
        long long num;
        scanf("%lld", &num);
        num--;
        num %= flatsInHouse;
        printf("%d\n", binSearch(num + 1, nFloors, kExtra, xExtra, x));
    }
    return 0;
}