#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long startId, textIdSum;
    scanf("%lld %lld", &startId, &textIdSum);
    long long count = 0;
    long long sum = 0;
    for (long long i = 1; sum < textIdSum; i++) {
        sum += startId + i;
        count++;
    }
    long long ans = startId;
    if (sum > textIdSum) {
        sum -= startId + count;
        count--;
        ans += (textIdSum - sum + count - 1) / count;
    }
    printf("%lld", ans);
    return 0;
}