#include <stdio.h>
#include <string>
#include <unordered_map>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int PRIME = 31;
    const int MOD = (int)1e9 + 7;
    std::unordered_map<int, std::unordered_map<int, int>> mp;
    int nQ;
    scanf("%d", &nQ);
    for (int q = 0; q < nQ; q++) {
        long long hash = 0;
        long long pow = 1;
        int type;
        scanf("%d", &type);
        if (type == 1) {
            char buf[1 + 100000];
            scanf("%s", &buf);
            std::string s(buf);
            for (int i = 0; i < (int)s.length(); i++) {
                hash += pow * (s[i] - 'a' + 1) % MOD;
                pow = pow * PRIME % MOD;
                mp[i][hash]++;
            }
        } else if (type == 2) {
            char buf[1 + 100000];
            scanf("%s", &buf);
            std::string s(buf);
            for (int i = 0; i < (int)s.length(); i++) {
                hash += pow * (s[i] - 'a' + 1) % MOD;
                pow = pow * PRIME % MOD;
                mp[i][hash]--;
                if (mp[i][hash] == 0) {
                    mp[i].erase(hash);
                }
            }
        } else if (type) {
            int len;
            scanf("%d", &len);
            printf("%d\n", (int)mp[len - 1].size());
        }
    }
    return 0;
}
