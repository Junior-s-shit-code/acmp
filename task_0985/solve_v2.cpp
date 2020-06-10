#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

int getType(std::unordered_map <std::string, int> &types) {
	char buf[1 + 30];
	scanf("%s", &buf);
	return types[std::string(buf)];
}

std::vector <int> getSizes() {
	char c;
	std::vector <int> ans;
	while (true) {
		int code = scanf("%c", &c);
		if (code == EOF || c == '\n') {
			break;
		}
		if (c == '[') {
			std::string value = "";
			while (true) {
				scanf("%c", &c);
				if (c == ']') {
					break;
				}
				value += c;
			}
			ans.push_back(std::atoi(value.c_str()));
		}
	}
	return ans;
}

int getCalculation(const int typeValue, const int curIndex, std::vector <int> &size) {
	if (curIndex + 1 == (int)size.size()) {
		return 24 + size[curIndex] * typeValue;
	} else {
		return 24 + size[curIndex] * (getCalculation(typeValue, curIndex + 1, size));
	}
}

void solve(std::unordered_map <std::string, int> &types) {
	int typeValue = getType(types);
	std::vector <int> size = getSizes();
	printf("%d\n", getCalculation(typeValue, 0, size));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::unordered_map <std::string, int> types;
	for (int i = 0; i < n; i++) {
		char buf[1 + 30];
		int value;
		scanf(" %s %d", &buf, &value);
		types[std::string(buf)] = value;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		solve(types);
	}
	return 0;
}