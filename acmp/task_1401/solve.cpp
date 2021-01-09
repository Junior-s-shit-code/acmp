#include <stdio.h>
#include <vector>
#include <algorithm>

struct Info {

    int value;

    int counter;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, mult;
    scanf("%d %d", &n, &mult);
    std::vector<int> input(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    std::sort(input.begin(), input.end());
    std::vector<Info> a;
    int counter = 1;
    int value = input[0];
    for (int i = 1; i < n; i++) {
        if (value != input[i]) {
            a.push_back(Info{ value, counter });
            value = input[i];
            counter = 1;
        } else {
            counter++;
        }
    }
    a.push_back(Info{ value, counter });
    int twoCount = 0;
    int maxNumberId = 0;
    long long ans = 0;
    int nInfo = (int)a.size();
    for (int i = 0; i + 1 < nInfo; i++) {
        if (a[i].counter >= 3) {
            ans++;
        }
        if (i > 0 && a[i].counter >= 2) {
            twoCount--;
        }
        while (maxNumberId + 1 < nInfo && 1LL * a[i].value * mult >=  a[maxNumberId + 1].value) {
            maxNumberId++;
            if (a[maxNumberId].counter >= 2) {
                twoCount++;
            }
        }
        long long nNext = 0LL + maxNumberId - i;
        long long ABCsum = 1LL * nNext * (nNext - 1) * 3;
        long long ABBsum = twoCount * 3;
        long long AABsum = 0;
        if (a[i].counter >= 2) { 
            AABsum = nNext * 3; 
        }
        ans += ABCsum + ABBsum + AABsum;
    }
    if (a[nInfo - 1].counter >= 3) {
        ans++;
    }
    printf("%lld", ans);
    return 0;
}