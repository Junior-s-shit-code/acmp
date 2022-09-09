#include <stdio.h>
#include <string>

bool isPalindrome(
    const char c,
    const int len,
    const std::string &s,
    int &deleted
) {
    int left = 0;
    int right = len - 1;
    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else if (s[left] == c) {
            left++;
            deleted++;
        } else if (s[right] == c) {
            right--;
            deleted++;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    const int INF = 2e5;
    int nT;
    scanf("%d", &nT);
    for (int t = 0; t < nT; t++) {
        int len;
        scanf("%d", &len);
        char buf[1 + 200000];
        scanf("%s", &buf);
        std::string s(buf);
        int minDeleted = INF;
        for (char deleteChar = 'a'; deleteChar <= 'z'; deleteChar++) {
            int curDeleted = 0;
            if (isPalindrome(deleteChar, len, s, curDeleted) && curDeleted < minDeleted) {
                minDeleted = curDeleted;
            }
        }
        printf("%d\n", minDeleted == INF ? -1 : minDeleted);
    }
    return 0;
}