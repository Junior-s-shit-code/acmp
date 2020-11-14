#include <stdio.h>
#include <algorithm>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int count2 = 0;
	int count5 = 0;
	while (n % 5 == 0) {
		n /= 5;
		count5++;
	}
	while (n % 2 == 0) {
		n /= 2;
		count2++;
	}
	if (n != 1) {
		printf("NO");
	} else {
		printf("%d", std::max(count2, count5));
	}
	return 0;
}