#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int curHour, time;
    scanf("%d %d", &curHour, &time);
    while (time > 0) {
        if (curHour == 8 || curHour == 13 || curHour == 18) {
            curHour++;
            continue;
        }
        curHour++;
        time--;
    }
    printf("%d", curHour);
    return 0;
}