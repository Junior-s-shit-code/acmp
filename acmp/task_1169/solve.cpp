#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int Ax, Ay, Bx, By;
	scanf("%d %d %d %d", &Ax, &Ay, &Bx, &By);
	int xDiff = Bx - Ax;
	int yDiff = By - Ay;
	printf("%d %d", Bx + xDiff, By + yDiff);
	return 0;
}