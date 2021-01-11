#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const long long INF = (long long)1e18;
    long long num;
    int a, b, c;
    scanf("%lld %d %d %d", &num, &a, &b, &c);
    std::vector<std::vector<std::vector<long long>>> count(a + 1, std::vector<std::vector<long long>>(b + 1, std::vector<long long>(c + 1, INF)));
    count[a][b][c] = num;
    for (int i = a; i >= 0; i--) {
        for (int j = b; j >= 0; j--) {
            for (int k = c; k >= 0; k--) {
                if (i > 0) {
                    count[i - 1][j][k] = std::min(count[i - 1][j][k], count[i][j][k] >> 1);
                }
                if (j > 0) {
                    count[i][j - 1][k] = std::min(count[i][j - 1][k], (count[i][j][k] + 1) >> 1);
                }
                if (k > 0) {
                    count[i][j][k - 1] = std::min(count[i][j][k - 1], std::max(0LL, (count[i][j][k] - 1) >> 1));
                }
            }
        }
    }
    printf("%lld", count[0][0][0]);
    return 0;
}