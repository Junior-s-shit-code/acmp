#include <stdio.h>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstdlib>

struct Num {

    int fullNum;

    int len;

    std::string strNum;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int INF = (int)1e6;
    int number;
    scanf("%d", &number);
    std::string toParse = "123456789";
    std::vector<Num> nums;
    std::vector<int> minLen(number + 1, INF);
    minLen[0] = 0;
    for (int len = 1; len <= 6; len++) {
        for (int start = 0; start + len <= (int)toParse.length(); start++) {
            std::string str = toParse.substr(start, len);
            int value = std::atoi(str.c_str());
            std::string add = str;
            if (len > 2) {
                add = str[0];
                add += '-';
                add += str[len - 1];
            }
            add += '+';
            nums.push_back(Num{ value, (int)add.length(), add });
            if (value <= number) {
                minLen[value] = (int)add.length();
            }
        }
    }
    std::sort(nums.begin(), nums.end(), [](const Num &left, const Num &right) {
        return std::to_string(left.fullNum) < std::to_string(right.fullNum);
    });
    int n = (int)nums.size();
    for (int i = 1; i < number; i++) {
        for (int j = 0; j < n; j++) {
            int curLen = minLen[i] + nums[j].len;
            int nextValue = i + nums[j].fullNum;
            if (nextValue <= number && curLen < minLen[nextValue]) {
                minLen[nextValue] = curLen;
            }
        }
    }
    std::vector<std::string> ans;
    while (number > 0) {
        for (int i = 0; i < n; i++) {
            int newNumber = number - nums[i].fullNum;
            if (newNumber >= 0 && minLen[number] == nums[i].len + minLen[newNumber]) {
                ans.push_back(nums[i].strNum);
                number = newNumber;
                break;
            }
        }
    }

    std::sort(ans.begin(), ans.end());
    std::string ansStr = "";
    for (int i = 0; i < (int)ans.size(); i++) {
        ansStr += ans[i];
    }
    ansStr.erase(ansStr.end() - 1);
    printf("%s", ansStr.c_str());
    return 0;
}