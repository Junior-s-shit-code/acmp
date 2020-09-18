#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char buf[1 + 100000];
    scanf("%s", &buf);
    std::string str1(buf);
    scanf("%s", &buf);
    std::string str2(buf);
    const int ALPHABET_SIZE = 26;
    std::vector<int> countSymbols1(ALPHABET_SIZE, 0);
    std::vector<int> countSymbols2(ALPHABET_SIZE, 0);
    int n = (int)str1.length();

    for (int i = 0; i < n; i++) {
        countSymbols1[str1[i] - 'a']++;
        countSymbols2[str2[i] - 'a']++;
    }
    long long ans = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        long long curSum = 0;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            int diff = std::abs(i - j);
            curSum += 1LL * countSymbols1[i] * countSymbols2[j] * std::min(diff, 26 - diff);
        }
        ans += curSum * n;
    }
    printf("%lld", ans);
    return 0;
}