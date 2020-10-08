#include <stdio.h>

struct Box {

    int x;

    int y;

    int z;

    static Box read() {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        return Box{ x, y, z };
    }

    int getV() {
        return x * y * z;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Box first = Box::read();
    Box second = Box::read();
    int v1 = first.getV();
    int v2 = second.getV();
    if (v1 > v2) {
        printf("FIRST");
    } else if (v1 < v2) {
        printf("SECOND");
    } else {
        printf("EQUAL");
    }
    return 0;
}