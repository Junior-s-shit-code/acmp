#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

struct Student {

    std::string name;

    int value;

    static Student read() {
        char buf[1 + 20];
        int value;
        scanf("%s %d", &buf, &value);
        return Student{ std::string (buf), value};
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    std::vector<Student> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = Student::read();
    }
    std::sort(a.begin(), a.end(), [](const Student &left, const Student &right) {
        return left.value < right.value;
    });
    std::sort(a.begin(), a.begin() + k, [](const Student &left, const Student &right) {
        return left.name < right.name;
    });
    for (int i = 0; i < k; i++) {
        printf("%s\n", a[i].name.c_str());
    }
    return 0;
}