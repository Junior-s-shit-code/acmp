#include <stdio.h>
#include <vector>
#include <algorithm>

struct TwoCell {

    short a;

    short b;

    static TwoCell read() {
        short a, b;
        scanf("%hi %hi", &a, &b);
        return TwoCell{ a, b };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector <TwoCell> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = TwoCell::read();
    }
    std::sort(a.begin(), a.end(), [](const TwoCell& left, const TwoCell& right) {
        return left.a + left.b > right.a + right.b;
    });
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans += a[i].a;
        } else {
            ans -= a[i].b;
        }
    }
    printf("%lld", ans);
    return 0;
}