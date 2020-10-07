#include <stdio.h>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <climits>
#include <cstdlib>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const long long LIMIT = LLONG_MAX;
    long long num;
    scanf("%lld", &num);
    std::unordered_set<long long> defaultNumbers;
    std::unordered_set<long long> allNumbers;
    std::string str = "2";
    while (true) {
        if (std::atoll(str.c_str()) >= num) {
            defaultNumbers.insert(std::atoll(str.c_str()));
            allNumbers.insert(std::atoll(str.c_str()));
            break;
        }
        defaultNumbers.insert(std::atoll(str.c_str()));
        allNumbers.insert(std::atoll(str.c_str()));
        str += "2";
    }
    long long ans = LIMIT;
    while (true) {
        bool isAdd = false;
        const int aSize = (int)defaultNumbers.size();
        const int setSize = (int)allNumbers.size();
        int i = 0;
        for (long long item : allNumbers) {
            if (num <= item && item < ans) {
                ans = item;
            }
            for (long long mult : defaultNumbers) {
                if (item <= LIMIT / mult && item * mult < ans &&
                    allNumbers.find(item * mult) == allNumbers.end()) {
                    allNumbers.insert(item * mult);
                    isAdd = true;
                }
            }
            i++;
            if (i >= setSize) {
                break;
            }
        }
        if (!isAdd) {
            break;
        }
    }
    printf("%lld", ans);
    return 0;
}