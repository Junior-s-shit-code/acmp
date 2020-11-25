#include <stdio.h>
#include <algorithm>

long long binSearch(int n, int w, int h) {
    long long left = 0;
    long long right = 1LL * n * std::max(w, h);
    while (left + 1 < right) {
        long long mid = (left + right) >> 1;
        if (1.0 * (mid / w) * (mid / h) < n) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return right;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, w, h;
    scanf("%d %d %d", &w, &h, &n);
    printf("%lld", binSearch(n, w, h));
    return 0;
}