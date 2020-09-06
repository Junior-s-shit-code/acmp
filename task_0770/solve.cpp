#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int maxSize = 500000;
    char buf[1 + maxSize];
    scanf("%s", &buf);
    std::string str(buf);
    int nWord = 0;

    for (int i = 0; i < (int)str.length(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            nWord++;
        }
    }
    int n = 0;
    int curSize = 1;
    for (int i = 0; i < (int)str.length(); curSize++) {
        if (i < (int)str.length()) {
            n++;
            i += curSize;
        } else {
            break;
        }
    }

    int left = 0;
    int right = (int)str.length() - 1;
    int curGroupSize = 1;
    std::vector <std::string> a(n);
    while (left <= right) {
        int curLen = std::min(curGroupSize, right - left + 1);
        if (curGroupSize % 2 == 1) {
            a[curGroupSize / 2] = str.substr(right - curLen + 1, curLen);
            right -= curLen;
        } else {
            a[n - curGroupSize / 2] = str.substr(left, curLen);
            left += curLen;
        }
        curGroupSize++;
    }
    
    std::string newStr = "";
    for (int i = 0; i < n; i++) {
        newStr += a[i];
    }
    std::vector <bool> isPrime(nWord + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= nWord; i++) {
        if (isPrime[i]) {
            if (1LL * i * i <= nWord) {
                for (long long j = 1LL * i * i; j <= nWord; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    int count = 1;
    bool isPrint = false;
    for (int i = 0; i < (int)newStr.length(); i++) {
        char c = newStr[i];
        if (isPrime[count]) {
            printf("%c", c);
            isPrint = true;
        }
        if (i + 1 < (int)newStr.length() && 'A' <= newStr[i + 1] && newStr[i + 1] <= 'Z') {
            count++;
        }
    }
    if (!isPrint) {
        printf("Impossible");
    }
    return 0;
}