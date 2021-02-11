#include <stdio.h>
#include <string>
#include <unordered_map>
#include <algorithm>

void fillMap(
    std::unordered_map<char, int> &mp,
    std::unordered_map<int, std::string> &rmp
) {
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    mp['/'] = 0;

    rmp[1] = 'I';
    rmp[4] = "IV";
    rmp[5] = 'V';
    rmp[9] = "IX";
    rmp[10] = 'X';
    rmp[40] = "XL";
    rmp[50] = 'L';
    rmp[90] = "XC";
    rmp[100] = 'C';
    rmp[400] = "CD";
    rmp[500] = 'D';
    rmp[900] = "CM";
    rmp[1000] = 'M';
}

int convertToDecimal(
    std::string s,
    std::unordered_map<char, int> &mp
) {
    int result = 0;
    int prevValue = 10000;
    int curDigitSum = 0;
    for (const char digit : s) {
        int curValue = mp[digit];
        if (prevValue == curValue) {
            curDigitSum += curValue;
        } else if (prevValue > curValue) {
            result += curDigitSum;
            curDigitSum = curValue;
        } else {
            result -= curDigitSum;
            curDigitSum = curValue;
        }
        prevValue = curValue;
    }
    return result + curDigitSum;
}


std::string convertToRoman(
    int number,
    std::unordered_map<int, std::string> &rmp
) {
    std::string result = "";
    while (number > 0) {
        int maxLower = 0;
        std::string add;
        for (const auto item : rmp) {
            if (number >= item.first && item.first > maxLower) {
                maxLower = item.first;
                add = item.second;
            }
        }
        number -= maxLower;
        result += add;
    }
    return result;
}

int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::unordered_map<char, int> mp;
    std::unordered_map<int, std::string> rmp;
    fillMap(mp, rmp);
    char buf[1 + 100];
    scanf("%s", &buf);
    std::string s(buf);

    bool isError = false;
    int slashId = -1;
    for (int i = 0; i < (int)s.length(); i++) {
        if (mp.find(s[i]) == mp.end()) {
            isError = true;
        } else if (slashId != -1 && s[i] == '/') {
            isError = true;
        } else if (s[i] == '/') {
            slashId = i;
        } 
    }
    if (slashId == -1 || slashId == 0 || slashId + 1 == (int)s.length() || isError) {
        printf("ERROR");
        return 0;
    }
    
    int dividend = convertToDecimal(s.substr(0, slashId), mp);
    int divisor = convertToDecimal(s.substr(slashId + 1), mp);
    if (s.substr(0, slashId) != convertToRoman(dividend, rmp) ||
        s.substr(slashId + 1) != convertToRoman(divisor, rmp)
    ) {
        printf("ERROR");
        return 0;
    }
    int curGcd = gcd(dividend, divisor);
    dividend /= curGcd;
    divisor /= curGcd;

    std::string rDividend = convertToRoman(dividend, rmp).c_str();
    std::string rDivisor = convertToRoman(divisor, rmp).c_str();

    printf("%s", rDividend.c_str());
    if (divisor > 1) {
        printf("/%s", rDivisor.c_str());
    }
    return 0;
}