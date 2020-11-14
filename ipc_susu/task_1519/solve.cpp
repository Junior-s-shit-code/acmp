#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int curHour, time;
    scanf("%d %d", &curHour, &time);
    for (int t = time; t > 0; t--) {
        curHour++;
        if (curHour == 8 || curHour == 13 || curHour == 18) {
            t++;
        }
    }
    printf("%d", curHour);
    return 0;
}