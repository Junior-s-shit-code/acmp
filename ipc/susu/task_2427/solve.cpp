#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

const int NOT_GOOD = -1;
const int UNKNOWN = 0;
const int GOOD = 1;

int sumDigitsSquare(int num) {
	int ans = 0;
	while (num > 0) {
		int d = num % 10;
		ans += d * d;
		num /= 10;
	}
	return ans;
}

int isWanted(int num, std::vector<int> &numberType) {
	if (numberType[num] == UNKNOWN) {
		numberType[num] = NOT_GOOD;
		if (isWanted(sumDigitsSquare(num), numberType) == GOOD) {
			numberType[num] = GOOD;
		}
	}
	return numberType[num];
}

int getNumber() {
	char buf[1 + 100];
	scanf("%s", &buf);
	std::string number(buf);
	int sumDigits2 = 0;
	for (int i = 0; i < (int)number.length(); i++) {
		int d = number[i] - '0';
		sumDigits2 += d * d;
	}
	return sumDigits2;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int SIZE = 81 * 100 + 1;
	std::vector<int> numberType(SIZE, UNKNOWN);
	numberType[0] = NOT_GOOD;
	numberType[1] = GOOD;
	int number = getNumber();
	printf(isWanted(number, numberType) == GOOD ? "YES" : "NO");
	return 0;
}