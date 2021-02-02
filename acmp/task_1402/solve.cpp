#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

const int MOD = (int)1e9 + 7;
const int MAX_K = 8;
const int MAX_N = 100 + MAX_K;

std::vector<std::vector<int>> cnk(1 + MAX_N, std::vector<int>(1 + MAX_K, 0));

int c(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    if (cnk[n][k] == 0) {
        long long value = 0LL + c(n - 1, k - 1) + c(n - 1, k);
        cnk[n][k] = value % MOD;
    }
    return cnk[n][k];
}

bool isInteresting(const std::string &str) {
    for (int i = 1; i < (int)str.length(); i++) {
        if (str[i - 1] > str[i]) {
            return false;
        }
    }
    return true;
}

int countBefore(const std::string &str) {
    int ans = 0;
    for (int len = 1; len < (int)str.length(); len++) {
        ans += c(len + 8, 8);
        ans %= MOD;
    }
    for (int prefLen = 1; prefLen <= (int)str.length(); prefLen++) {
        for (char last = '1'; last < str[prefLen - 1]; last++) {
            std::string prefix = str.substr(0, prefLen);
            prefix[prefLen - 1] = last;
            if (isInteresting(prefix)) {
                int suffLen =  (int)str.length() - prefLen;
                int rem = '9' - last;
                ans += c(suffLen + rem, rem);
                ans %= MOD;
            }
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char buf[1 + 101];
    scanf("%s", &buf);
    std::string min(buf);
    scanf("%s", &buf);
    std::string max(buf);
    long long ans = 0LL + countBefore(max) - countBefore(min);
    if (isInteresting(max)) {
        ans++;
    }
    ans += MOD;
    printf("%lld", ans % MOD);
    return 0;
}