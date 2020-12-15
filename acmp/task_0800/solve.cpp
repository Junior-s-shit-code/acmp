#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>

int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int total = 0;

void count(int lastD,
           int p,
           int rem,
           const int nD,
           const int n,
           int &total,
           const std::vector<std::vector<double>> &minProduct,
           const std::vector<std::vector<bool>> &coprime, 
           const std::vector<int> &divisors
) {
    if (rem == 0) {
        total++;
        return;
    }
    for (int curD = lastD + 1; curD < nD && p * minProduct[rem][curD] <= n; curD++) {
        if (coprime[lastD][curD]) {
            count(curD, p * divisors[curD], rem - 1, nD, n, total, minProduct, coprime, divisors);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, nMult;
    scanf("%d %d", &n, &nMult);
    std::vector<int> divisors;
    for (int d = 1; d <= n / d; d++) {
        if (n % d == 0) {
            divisors.push_back(d);
        }
    }
    for (int i = (int)divisors.size() - 1; i >= 0; i--) {
        if (divisors[i] * divisors[i] != n) {
            divisors.push_back(n / divisors[i]);
        }
    }
    int nD = (int)divisors.size();
    std::vector<std::vector<bool>> coprime(nD, std::vector<bool>(nD));
    for (int i = 0; i < nD; i++) {
        for (int j = i; j < nD; j++) {
            coprime[i][j] = gcd(divisors[i], divisors[j]) == 1;
            coprime[j][i] = coprime[i][j];
        }
    }
    std::vector<std::vector<double>> minProduct(1 + nMult, std::vector<double>(nD + 1));
    for (int m = 1; m <= nMult; m++) {
        for (int d = 0; d <= nD; d++) {
            if (d == nD) {
                minProduct[m][d] = n + 1;
            } else if (m == 1) {
                minProduct[m][d] = divisors[d];
            } else {
                minProduct[m][d] = minProduct[m - 1][d + 1] * divisors[d];
            }
        }
    }
   
    for (int d = 0; d < nD; d++) {
        count(d, divisors[d], nMult - 1, nD, n, total, minProduct, coprime, divisors);
    }
    printf("%d", total);

    return 0;
}