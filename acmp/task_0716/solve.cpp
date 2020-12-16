#include <stdio.h>
#include <vector>
#include <string>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    double left = 30.0;
    double right = 4000.0;
    double cur, prev;
    int n;
    scanf("%d %lf", &n, &prev);
    for (int i = 0; i + 1 < n; i++) {
        char buf[10];
        scanf("%lf %s", &cur, &buf);
        bool closer = std::string(buf) == "closer";
        if (cur > prev && closer ||
            cur < prev && !closer
        ) {
            left = std::max(left, (cur + prev) / 2);
        } else if (cur != prev) {
            right = std::min(right, (cur + prev) / 2);
        }
        prev = cur;
    }
    printf("%.6lf %.6lf", left, right);
    return 0;
}