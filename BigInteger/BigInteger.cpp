#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

class BigInteger {
	std::vector <short int> value;

public:

	static BigInteger valueOf(long long num) {
		BigInteger bigNum;
		while (num != 0) {
			if (num < 0) {
				bigNum.value.push_back(-1 * ((-num) % 10));
				num *= -1;
			} else {
				bigNum.value.push_back(num % 10);
			}
			num /= 10;
		}
		return bigNum;
	}

	std::string toString() {
		std::string ans = "";
		bool isNum = false;
		for (int i = (int)value.size() - 1; i >= 0; i--) {
			if (isNum || i == 0) {
				ans += std::to_string(value[i]);
			} else if (!isNum && value[i] != 0) {
				ans += std::to_string(value[i]);
				isNum = true;
			}
		}
		return ans;
	}

	BigInteger operator + (BigInteger &second) {
		BigInteger num;
		int curSize = (int)value.size();
		int secSize = (int)second.value.size();
		num.value = std::vector <short int> (std::max(curSize, secSize) + 1);
		for (int i = 0; i < std::max(curSize, secSize); i++) {

			if (i < curSize) {
				num.value[i] += value[i];
			}
			if (i < secSize) {
				num.value[i] += second.value[i];
			}

			num.value[i + 1] += num.value[i] / 10;
			num.value[i] %= 10;
		}
		return num;
	}

	BigInteger operator * (BigInteger &second) {
		BigInteger num;
		int curSize = (int)value.size();
		int secSize = (int)second.value.size();
		int maxSize = std::max(curSize, secSize);
		num.value = std::vector <short int> (curSize + secSize, 0);
		for (int i = 0; i < curSize; i++) {
			for (int j = 0; j < secSize; j++) {

				if (i + j == num.value.size()) {
					num.value.push_back(0);
				}
				num.value[i + j] += value[i] * second.value[j];
				num.value[i + j + 1] += num.value[i + j] / 10;
				num.value[i + j] %= 10;
			}
		}
		return num;
	}
};
