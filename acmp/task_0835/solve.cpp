#include <stdio.h>
#include <vector>
#include <algorithm>

struct Item {

    int weight;

    int value;

    int id;

    static Item read(const int id) {
        int weight, value;
        scanf("%d %d", &weight, &value);
        return Item{ weight, value, id };
    }
};

long long getSetValue(
    int iCombination,
    const int n,
    const long long maxWeight,
    const std::vector<Item> &a
) {
    long long sumValue = 0;
    long long sumWeight = 0;
    for (int iItem = 0; iItem < n; iItem++) {
        if ((iCombination & 1) == 1) {
            sumValue += a[iItem].value;
            sumWeight += a[iItem].weight;
        }
        iCombination >>= 1;
    }
    return sumWeight <= maxWeight ? sumValue : -1;
}

int chooseCombination(
    const int combination1,
    const int combination2,
    const int n
) {
    int value1 = combination1;
    int value2 = combination2;
    if (__builtin_popcount(value1) == __builtin_popcount(value2)) {
        int counter1 = 0;
        int counter2 = 0;
        while (value1 > 0 && value2 > 0) {
            int dig1 = (value1 & 1);
            int dig2 = (value2 & 1);
            if (dig1 == 1 && dig2 == 0) {
                return combination1;
            } else if (dig1 == 0 && dig2 == 1) {
                return combination2;
            }
            value1 >>= 1;
            value2 >>= 1;
        }
    }
    return __builtin_popcount(combination1) < __builtin_popcount(combination2) ? combination1 : combination2;
}

void print(
    int num,
    const long long value,
    const int n
) {
    int nElements = __builtin_popcount(num);
    printf("%d %lld\n", nElements, value);
    for (int i = 1; i <= n; i++) {
        if ((num & 1) == 1) {
            printf("%d ", i);
        }
        num >>= 1;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    long long maxWeight;
    scanf("%d %d", &n, &maxWeight);
    std::vector<Item> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = Item::read(i);
    }
    int MAX_COMBINATIONS = (1 << n);
    
    int bestCombination = 0;
    long long bestValue = 0;
    for (int iCombination = 0; iCombination < MAX_COMBINATIONS; iCombination++) {
        long long curValue = getSetValue(iCombination, n, maxWeight, a);
        if (curValue > bestValue) {
            bestValue = curValue;
            bestCombination = iCombination;
        } else if (curValue == bestValue) {
            bestCombination = chooseCombination(bestCombination, iCombination, n);
        }
    }
    print(bestCombination, bestValue, n);
    return 0;
}