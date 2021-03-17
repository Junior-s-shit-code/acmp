#include <stdio.h>
#include <string>

char getComplimentar(char c) {
    if (c == 'A') {
        return 'T';
    } else if (c == 'T') {
        return 'A';
    } else if (c == 'C') {
        return 'G';
    } else if (c == 'G') {
        return 'C';
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    char buf[1 + 1000000];
    scanf("%d %s", &n, &buf);
    std::string s(buf);
    for (int i = 0; i < (int)s.length() / 2; i++) {
        if (s[i] != getComplimentar(s[n - i - 1])) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}