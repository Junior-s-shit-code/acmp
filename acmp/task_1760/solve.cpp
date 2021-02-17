#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nGroups, nPeople, nTeachers;
    scanf("%d %d %d", &nGroups, &nPeople, &nTeachers);
    printf("%d", nGroups * (nPeople - nTeachers));
    return 0;
}