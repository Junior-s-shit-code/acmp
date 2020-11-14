#include <stdio.h>
#include <string>
#include <algorithm>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char buf[1 + 200];
	scanf("%s", &buf);
	std::string str(buf);
	int nQ;
	scanf("%d", &nQ);
	for (int i = 0; i < nQ; i++) {
		char type;
		int left, right;
		scanf(" %c %d %d", &type, &left, &right);
		if (type == 'S') {
			std::sort(str.begin() + left - 1, str.begin() + right);
		} else {
			std::reverse(str.begin() + left - 1, str.begin() + right);
		}
	}
	printf("%s", str.c_str());
	return 0;
}