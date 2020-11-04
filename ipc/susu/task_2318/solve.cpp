#include <stdio.h>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int start1, end1, start2, end2;
    scanf("%d %d %d %d", &start1, &end1, &start2, &end2);
    int ans;
    if ((start2 <= start1 && start1 <= end2 || start1 <= start2 && end2 <= start1) &&
        (start1 < end1 && start2 < end2 || end1 < start1 && end2 < start2)
    ) {
        if (start2 <= end1 && end1 <= end2 || end1 <= start2 && end2 <= end1) {
            ans = std::abs(start1 - start2) +
                std::abs(end1 - start1) + 2;
        } else {
            ans = std::abs(start1 - start2) +
                std::abs(end2 - start1) +
                std::abs(end1 - end2) + 3;
        }
    } else {
        ans = std::abs(end2 - start2) +
            std::abs(start1 - end2) +
            std::abs(end1 - start1) + 3;
    }
    if (start1 == end2) {
        ans--;
    }
    printf("%d", ans);
    return 0;
}