#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<std::vector<bool>> readMatrix() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<bool>> matrix(sizeI, std::vector<bool> (sizeJ, false));
    int minI = sizeI;
    int maxI = 0;
    int minJ = sizeJ;
    int maxJ = 0;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            char c;
            scanf(" %c", &c);
            if (c == '#') {
                matrix[i][j] = true;
                minI = std::min(minI, i);
                maxI = std::max(maxI, i);
                minJ = std::min(minJ, j);
                maxJ = std::max(maxJ, j);
            }
        }
    }
    int newSizeI = maxI - minI + 1;
    int newSizeJ = maxJ - minJ + 1;
    std::vector<std::vector<bool>> newMatrix(newSizeI, std::vector<bool> (newSizeJ));
    for (int i = 0; i < newSizeI; i++) {
        for (int j = 0; j < newSizeJ; j++) {
            newMatrix[i][j] = matrix[minI + i][minJ + j];
        }
    }
    return newMatrix;
}

bool compare(
    const int sizeI,
    const int sizeJ,
    const std::vector<std::vector<bool>> &a,
    const std::vector<std::vector<bool>> &b
) {
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void rotate(
    const int sizeI,
    const int sizeJ,
    std::vector<std::vector<bool>> &a
) {
    std::vector<std::vector<bool>> b(sizeJ, std::vector<bool> (sizeI));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            b[sizeJ - j - 1][i] = a[i][j];
        }
    }
    a = b;
}

void reflect(std::vector<std::vector<bool>> &a) {
    int sizeI = (int)a.size();
    for (int i = 0; i < sizeI/ 2; i++) {
        std::swap(a[i], a[sizeI - i - 1]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::vector<std::vector<bool>> a = readMatrix();
    std::vector<std::vector<bool>> b = readMatrix();
    int sizeI_A = (int)a.size();
    int sizeJ_A = (int)a.size() != 0 ? (int)a[0].size() : 0;
    int sizeI_B = (int)b.size();
    int sizeJ_B = (int)b.size() != 0 ? (int)b[0].size() : 0;

    for (int iReflection = 0; iReflection < 2; iReflection++) {
        for (int iCount = 0; iCount < 4; iCount++)
        {
            if (sizeI_A == sizeI_B && sizeJ_A == sizeJ_B &&
                compare(sizeI_A, sizeJ_A, a, b))
            {
                printf("Yes");
                return 0;
            }
            rotate(sizeI_A, sizeJ_A, a);
            sizeI_A = (int)a.size();
            sizeJ_A = (int)a.size() != 0 ? (int)a[0].size() : 0;
        }
        reflect(a);
    }
    printf("No");
    return 0;
}