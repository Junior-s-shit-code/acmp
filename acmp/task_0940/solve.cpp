#include <stdio.h>
#include <string>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int index;
	scanf("%d", &index);
	char buf[1 + 80];
	scanf("%s", &buf);
	std::string str(buf);
	str.erase(str.begin() + index - 1);
	printf("%s", str.c_str());
	return 0;
}