#include <stdio.h>
#include <algorithm>
#include <vector>

int getIdStocking(int left, int right, const int ansDiff, const int iFirst, const std::vector<int> &a) {
    while (left < right) {
        int mid = (left + right) >> 1;
        if (a[mid] - a[iFirst] > ansDiff) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

long long countPairs(const int maxDiff, const int n, const std::vector<int> &a) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (long long)getIdStocking(i, n, maxDiff, i, a) - i - 1;
    }
    return ans;
}

int getAnsDiff(const long long ansDay, const int n, const std::vector<int> &a) {
    int left = 1;
    int right = (int)1e9;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (countPairs(mid, n, a) >= ansDay) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    long long ansDay;
    scanf("%d %lld", &n, &ansDay);
    std::vector<int> stockings(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stockings[i]);
    }
    int ansDiff = getAnsDiff(ansDay, n, stockings);
    ansDay -= countPairs(ansDiff, n, stockings);
    for (int iFirstStocking = n - 1; iFirstStocking >= 0; iFirstStocking--) {
        int iSecondStocking = getIdStocking(iFirstStocking, n, ansDiff, iFirstStocking, stockings) - 1;
        if (stockings[iSecondStocking] - stockings[iFirstStocking] == ansDiff) {
            if (ansDay == 0) {
                printf("%d %d", stockings[iFirstStocking], stockings[iSecondStocking]);
                return 0;
            } 
            ansDay++;
        }
    }
    return 0;
}