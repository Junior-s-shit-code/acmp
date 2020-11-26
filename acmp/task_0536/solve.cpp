#include <stdio.h>
#include <string>
#include <vector>
#include <cstdlib>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MAX_LEN = 10;
    int n, max, ext;
    scanf("%d %d %d", &n, &max, &ext);
    long long mod = 1;
    for (int i = 0; i < ext; i++) {
        mod *= 10;
    }
    std::vector<long long> a(n + 1, 0);
    char buf[1 + 50000];
    scanf("%s", &buf);
    std::string s(buf);

    std::string str;
    for (int len = 1; len < MAX_LEN && len <= n; len++) {
        str.insert(str.end(), s[len - 1]);
        if (str.length() > 1 && str[0] == '0' ||
            std::atoll(str.c_str()) > max
            ) {
            continue;
        }
        a[len] = 1;
    }

    for (int i = 1; i <= n; i++) {
        long long newValue = 0;
        long long ext = 1;
        for (int j = i; j > 0 && i - j < MAX_LEN; j--) {
            int add = s[j - 1] - '0';
            newValue = add * ext + newValue;
            ext *= 10;
            if (newValue > max) {
                break;
            }
            if (add > 0 || ext == 10) {
                a[i] += a[j - 1];
                a[i] %= mod;
            }
        }
    }

    printf("%lld", a[n]);
    return 0;
}