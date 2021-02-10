#include <stdio.h>
#include <string>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char buf[1 + 250];
    scanf("%s", &buf);
    std::string num(buf);
    int sum = 0;
    for (int i = 0; i < (int)num.length(); i++) {
        sum += num[i] - '0';
    }
    if (sum % 3 == 0) {
        printf("2");
    } else {
        printf("1\n%d", sum % 3);
    }
    return 0;
}