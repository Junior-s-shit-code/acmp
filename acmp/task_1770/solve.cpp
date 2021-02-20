#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int shark, shelter;
    scanf("%d %d", &shark, &shelter);
    for (int i = 0; i < n; i++) {
        a[i] = std::abs(shelter - a[i]);
    }
    std::sort(a.begin(), a.end());
    int counter = 0;
    int sharkDist = std::abs(shelter - shark);
    for (int i = 0; i < n; i++) {
        if (sharkDist - a[i] > 0) {
            sharkDist -= a[i];
            counter++;
        } else {
            break;
        }
    }
    printf("%d", counter);
    return 0;
}