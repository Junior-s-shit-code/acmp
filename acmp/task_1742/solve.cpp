#include <stdio.h>
#include <vector>
#include <unordered_map>

void calculateSuffixSums(
    const int n,
    std::vector<long long> &a
) {
    for (int i = n - 1; i >= 0; i--) {
        a[i] += a[i + 1];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<long long> countSegments(1 + n, 0);
    std::unordered_map<int, int> taskTypeToPos;
    for (int i = 0; i < n; i++) {
        int taskType;
        scanf("%d", &taskType);
        countSegments[i - taskTypeToPos[taskType]]++;
        taskTypeToPos[taskType] = i + 1;
    }
    for (auto const &entry : taskTypeToPos) {
        countSegments[n - entry.second]++;
    }
    calculateSuffixSums(n, countSegments);
    calculateSuffixSums(n, countSegments);
    long long nTypes = (long long)taskTypeToPos.size();
    for (int len = 1; len <= n; len++) {
        printf("%lld ", nTypes * (n - len + 1) - countSegments[len]);
    }
    return 0;
}