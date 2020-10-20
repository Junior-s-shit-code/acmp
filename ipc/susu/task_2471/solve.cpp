#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int counter = 0;
	while (n % 10 == 0) {
		n /= 10;
		counter++;
	}
	while (n % 5 == 0) {
		n /= 5;
		counter++;
	}
	while (n % 2 == 0) {
		n /= 2;
		counter++;
	}
	if (n != 1) {
		printf("NO");
	} else {
		printf("%d", counter);
	}
	return 0;
}