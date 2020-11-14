#include <stdio.h>
#include <string>

std::string createPalindromeFrom(std::string str) {
	for (int i = 0; i < (int)str.length() / 2; i++) {
		str[(int)str.length() - i - 1] = str[i];
	}
	return str;
}

std::string incrementLeftHalfOf(std::string str) {
	int extra = 1;
	int i = ((int)str.length() - 1) / 2;
	while (i >= 0) {
		if (str[i] == '9') {
			str[i] = '0';
			i--;
		} else {
			str[i]++;
			return str;
		}
	}
	return '1' + str;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char buf[1 + 100];
	scanf("%s", &buf);
	std::string str(buf);
	std::string ans = createPalindromeFrom(str);
	if (ans <= str) {
		ans = incrementLeftHalfOf(ans);
		ans = createPalindromeFrom(ans);
	}
	printf("%s", ans.c_str());
	return 0;
}