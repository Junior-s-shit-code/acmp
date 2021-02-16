#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int number;
    scanf("%d", &number);
    int counter = 0;
    int ansCode = -1;
    for (int codeLen = 2; codeLen <= 3; codeLen++) {
        for (int a = 2; a <= 9; a++) {
            for (int b = 2; b <= 9; b++) {
                if (codeLen == 3) {
                    for (int c = 2; c <= 9; c++) {
                        int curNum = a * 100 + b * 10 + c;
                        if (curNum * a * b * c == number && curNum != ansCode) {
                            counter++;
                            ansCode = curNum;
                        }
                    }
                } else {
                    int curNum = a * 10 + b;
                    if (curNum * a * b == number && curNum != ansCode) {
                        counter++;
                        ansCode = curNum;
                    }
                }
            }
        }
    }
    
    if (counter == 1) {
        printf("%d", ansCode);
    } else {
        printf("ERROR");
    }
    return 0;
}