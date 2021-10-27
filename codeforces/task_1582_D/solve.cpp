#include <stdio.h>
#include <vector>

void printValues(int n, const std::vector<int> &a) {
    for (int i = 0; i < n; i += 2) {
        printf("%d %d ", -a[i + 1], a[i]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    int nT;
    scanf("%d", &nT);
    for (int t = 0; t < nT; t++) {
        int n;
        scanf("%d", &n);
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        if (n % 2 == 1) {
            printValues(n - 3, a);
            int i = n - 3;
            int j = n - 2;
            int k = n - 1;
            if (a[i] + a[j] != 0) {
                printf("%d %d %d ", -a[k], -a[k], a[i] + a[j]);
            } else if (a[j] + a[k] != 0) {
                printf("%d %d %d ", a[j] + a[k], -a[i], -a[i]);
            } else {
                printf("%d %d %d ", -a[j], a[i] + a[k], -a[j]);
            }
        } else {
            printValues(n, a);
        }
        printf("\n");
    }
    return 0;
}