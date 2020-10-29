#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_set>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::unordered_set<long long> set;
    std::vector<long long> a(64, 0);
    int iElement = 0;
    int left = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[iElement]);
        for (int right = 0; right <= iElement; right++) {
            a[left] = gcd(a[right], a[iElement]);
            set.insert(a[left]);
            if (left == 0 || a[left] != a[left - 1]) {
                left++;
            }
        }
        iElement = left;
        left = 0;
    }
    printf("%d", (int)set.size());
    return 0;
}