#include <stdio.h>
#include <vector>
#include <algorithm>

struct BigInteger {
	static const int limit = (int) 1e9;
	std::vector <unsigned long long> value;

	static BigInteger valueOf(long long intValue) {
		BigInteger newValue;
		newValue.value.push_back(intValue % limit);
		newValue.value.push_back(intValue / limit);
		return newValue;
	}

	BigInteger operator + (BigInteger second) {
		int sizeCur = (int)value.size();
		int sizeSec = (int)second.value.size();
		int maxSize = std::max(sizeCur, sizeSec) + 1;

		BigInteger newValue;

		for (int i = 0; i < maxSize; i++) {
			unsigned long long sum = 0;
			if (i < sizeCur) {
				sum += value[i];
			}
			if (i < sizeSec) {
				sum += second.value[i];
			}
			newValue.value[i] += sum % limit;
			newValue.value.push_back(sum / limit);
		}
		return newValue;
	}

	BigInteger operator * (BigInteger second) {
		int sizeCur = (int)value.size();
		int sizeSec = (int)second.value.size();
		int maxSize = std::max(sizeCur, sizeSec);
		int minSize = std::min(sizeCur, sizeSec);

		BigInteger newValue;
		newValue.value.reserve(maxSize * 2 + 1);
		for (int i = 0; i < sizeCur; i++) {
			for (int j = 0; j < sizeSec; j++) {
				unsigned long long curValue = value[i] * second.value[j];
				if (i + 1 > (int) newValue.value.size()) {
					newValue.value.push_back(0);
					newValue.value.push_back(0);
				} else if (i + 1 == (int)newValue.value.size()) {
					newValue.value.push_back(0);
				}
				newValue.value[i] += curValue % limit;
				newValue.value[i + 1] += newValue.value[i] / limit;
				newValue.value[i] %= limit;
				newValue.value[i + 1] += curValue / limit;
			}
		}
		return newValue;
	}

};


void write(BigInteger &num) {
	bool isNum = false;
	for (int i = (int)num.value.size() - 1; i >= 0; i--) {
		if (isNum) {
			if (num.value[i] == 0) {
				printf("00000000");
			} else {
				printf("%lld", num.value[i]);
			}
		} else if (!isNum && num.value[i] != 0) {
			printf("%lld", num.value[i]);
			isNum = true;
		}
	}
}



int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	BigInteger num = BigInteger::valueOf(100000000);
	BigInteger num2 = BigInteger::valueOf(1000000000);
	num = num * num2;
	write(num);
	return 0;
}