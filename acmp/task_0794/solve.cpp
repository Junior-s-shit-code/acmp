#include <stdio.h>
#include <algorithm>

// O(1)
// math

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nPlayers, maxLvl, lvlPoint;
    scanf("%d %d %d", &nPlayers, &maxLvl, &lvlPoint);
    int ans = nPlayers * (maxLvl / lvlPoint + std::min(maxLvl, lvlPoint - 1));
    printf("%d", ans);
    return 0;
}