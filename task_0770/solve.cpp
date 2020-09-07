#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

std::string decode(const std::string str) {
    int left = 0;
    int right = (int)str.length() - 1;
    int curGroupSize = 1;
    std::string leftStr;
    std::string rightStr;
    while (left <= right) {
        int curLen = std::min(curGroupSize, right - left + 1);
        if (curGroupSize % 2 == 1) {
            leftStr += str.substr(right - curLen + 1, curLen);
            right -= curLen;
        } else {
            rightStr = str.substr(left, curLen) + rightStr;
            left += curLen;
        }
        curGroupSize++;
    }
    return leftStr + rightStr;
}

std::vector <bool> generatePrimeTill(const int nWord) {
    std::vector <bool> isPrime(nWord + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= nWord; i++) {
        if (isPrime[i]) {
            if (1LL * i * i <= nWord) {
                for (int j = 1LL * i * i; j <= nWord; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    return isPrime;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char buf[1 + 500000];
    scanf("%s", &buf);
    std::string str(buf);

    std::string newStr = decode(str);

    int nWord = 0;
    for (int i = 0; i < (int)newStr.length(); i++) {
        if ('A' <= newStr[i] && newStr[i] <= 'Z') {
            nWord++;
        }
    }
    
    std::vector <bool> isPrime = generatePrimeTill(nWord);

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