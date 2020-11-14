#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <set>

struct Num {

    int fullNum;

    int len;

    std::string strNum;
};

void fillNumbers(const int number, const std::string toParse, std::vector<Num> &nums) {
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
        }
    }
    std::sort(nums.begin(), nums.end(), [](const Num &left, const Num &right) {
        return std::to_string(left.fullNum) < std::to_string(right.fullNum);
    });
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int INF = (int)1e6;
    int number;
    scanf("%d", &number);
    std::string toParse = "123456789";
    std::vector<Num> nums;
    std::vector<int> minLen(number + 1, INF);
    //fill numbers
    fillNumbers(number, toParse, nums);
    minLen[0] = 0;
    //calc dp vector
    int nNumbers = (int)nums.size();
    for (int curNum = 0; curNum < number; curNum++) {
        for (int addNum = 0; addNum < nNumbers; addNum++) {
            int curLen = minLen[curNum] + nums[addNum].len;
            int nextValue = curNum + nums[addNum].fullNum;
            if (nextValue <= number && curLen < minLen[nextValue]) {
                minLen[nextValue] = curLen;
            }
        }
    }
    //get answer
    std::multiset<std::string> ans;
    while (number > 0) {
        for (int i = 0; i < nNumbers; i++) {
            int newNumber = number - nums[i].fullNum;
            if (newNumber >= 0 && minLen[number] == nums[i].len + minLen[newNumber]) {
                ans.insert(nums[i].strNum);
                number = newNumber;
                break;
            }
        }
    }

    std::string ansStr = "";
    for (std::string item : ans) {
        ansStr += item;
    }
    ansStr.erase(ansStr.end() - 1);
    printf("%s", ansStr.c_str());
    return 0;
}