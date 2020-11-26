#include <stdio.h>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, pos, minWantedGcd;
    scanf("%d %d %d", &n, &pos, &minWantedGcd);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end());
    std::vector<std::vector<bool>> pair(n, std::vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pair[i][j] = gcd(a[i], a[j]) >= minWantedGcd;
        }
    }

    const int MAX_CODE = 1 << n;
    std::vector<std::vector<long long>> count(n, std::vector<long long>(MAX_CODE, 0));

    for (int code = 1; code < MAX_CODE; code++) {
        for (int first = 0; first < n; first++) {
            if (((code >> first) & 1) == 0) {
                continue;
            }
            if (code == (1 << first)) {
                count[first][code] = 1;
            } else {
                int codeWithoutFirst = code - (1 << first);
                for (int second = 0; second < n; second++) {
                    if (((codeWithoutFirst >> second) & 1) == 1 && pair[first][second]) {
                        count[first][code] += count[second][codeWithoutFirst];
                    }
                }
            }
        }
    }

    int rem = (1 << n) - 1;
    std::vector<int> answer(n);
    for (int i = 0; i < n; i++) { // answer position 
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (((rem >> j) & 1) == 1 &&
                (i == 0 || gcd(answer[i - 1], a[j]) >= minWantedGcd)
            ) {
                if (count[j][rem] < pos) {
                    pos -= count[j][rem];
                } else {
                    answer[i] = a[j];
                    rem -= 1 << j;
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            printf("-1");
            return 0;
        }
    }
    for (int item : answer) {
        printf("%d ", item);
    }
    return 0;
}