#include <stdio.h>
#include <vector>

struct Item {

    int weight;

    int value;

    static Item read() {
        int weight, value;
        scanf("%d %d", &weight, &value);
        return Item{ weight, value };
    };
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, maxWeight;
    scanf("%d %d", &n, &maxWeight);
    std::vector<Item> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = Item::read();
    }
    int bestN = n + 1;
    long long bestValue = 0;
    long long bestCode = 0;
    for (int code = 1; code < (1 << (n + 1)); code++) {
        int curN = 0;
        long long curWeight = 0;
        long long curValue = 0;
        for (int i = 0; i < n; i++) {
            if (((code >> (n - i - 1)) & 1) > 0) {
                curN++;
                curWeight += a[i].weight;
                curValue += a[i].value;
            }
        }
        if (curWeight > maxWeight)  {
            continue;
        }
        else if (curValue > bestValue)  {
            bestN = curN;
            bestValue = curValue;
            bestCode = code;
        }
        else if (curValue == bestValue && curN < bestN)  {
            bestN = curN;
            bestCode = code;
        }
        else if (curValue == bestValue && 
            curN == bestN && code > bestCode
        ) {
            bestCode = code;
        }
    }
    printf("%d %lld\n", bestN, bestValue);
    for (int i = 0; i < n; i++) {
        if (((bestCode >> (n - i - 1)) & 1) > 0) {
            printf("%d ", i + 1);
        }
    }
    return 0;
}