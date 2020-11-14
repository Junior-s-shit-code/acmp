#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::stack<long long> s;
    long long curCoefficient = 1;
    long long ans = 0;
    bool was = false;
    for (int i = 0; i < n * 2; i++) {
        char buf[10];
        scanf("%s", &buf);
        std::string str(buf);
        if (str == "for") {
            long long value;
            scanf("%lld", &value);
            s.push(value);
            curCoefficient *= value;
            was = false;
        } else {
            if (!was) {
                ans += curCoefficient;
            }
            was = true;
            curCoefficient /= s.top();
            s.pop();
        }
    }
    printf("%lld", ans);
    return 0;
}