#include <stdio.h>
#include <string>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int start, end;
    char buf[1 + 20];
    scanf("%d %d %s", &start, &end, &buf);
    std::string type(buf);
    if (type == "auto" ||
        type == "freeze" && end < start ||
        type == "heat" && start < end
    ) {
        printf("%d", end);
    } else {
        printf("%d", start);
    }
    return 0;
}
