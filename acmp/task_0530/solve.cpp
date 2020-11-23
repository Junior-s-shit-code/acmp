#include <stdio.h>
#include <vector>

void readMatrix(
	const int sizeI,
	const int sizeJ,
	std::vector<std::vector<bool>> &a
) {
	char c;
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			scanf(" %c", &c);
			a[i][j] = (c == '1');
		}
	}
}

char useOperation(const bool a, const bool b, const std::vector<char> &returnedType) {
	int id = (a << 1) + b;
	return returnedType[id];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int OPTIONS_SIZE = 4;
	int sizeI, sizeJ;
	scanf("%d %d", &sizeJ, &sizeI);
	std::vector<std::vector<bool>> a(sizeI, std::vector<bool>(sizeJ));
	readMatrix(sizeI, sizeJ, a);
	std::vector<std::vector<bool>> b(sizeI, std::vector<bool>(sizeJ));
	readMatrix(sizeI, sizeJ, b);
	std::vector<char> option(OPTIONS_SIZE);
	for (int i = 0; i < OPTIONS_SIZE; i++) {
		scanf(" %c", &option[i]);
	}
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			printf("%c", useOperation(a[i][j], b[i][j], option));
		}
		printf("\n");
	}
	return 0;
}