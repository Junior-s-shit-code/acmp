#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, max, ext;
    scanf("%d %d %d", &n, &max, &ext);
    long long mod = 1;
    for (int i = 0; i < ext; i++) {
        mod *= 10;
    }
    std::vector <long long> a(n + 1, 0);
    char buf[1 + 50000];
    scanf("%s", &buf);
    std::string s(buf);
    for (int len = 1; len < 10 && len <= n; len++) {
        std::string str = s.substr(0, len);
        if (str.length() > 1 && str[0] == '0' ||
            std::atoll(str.c_str()) > max
        ) {
            continue;
        }
        a[len] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0 && i - j < 10; j--) {
            std::string str = s.substr(j - 1, i - j + 1);
            long long newVal = std::atoll(str.c_str());
            if (newVal > max) {
                break;
            }
            if (str.length() > 1 && str[0] == '0') {
                continue;
            }
            a[i] += a[j - 1];
            a[i] %= mod;
        }
    }

    printf("%lld", a[n]);
    return 0;
}