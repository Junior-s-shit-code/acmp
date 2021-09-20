#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const long long INF = LLONG_MAX;
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<long long>> d(nV, std::vector<long long>(nV, INF));
    for (int i = 0; i < nV; i++) {
        d[i][i] = 0;
    }
    for (int iE = 0; iE < nE; iE++) {
        int v1, v2;
        double distDouble;
        scanf("%d %d %lf", &v1, &v2, &distDouble);
        long long dist = (long long) std::round(distDouble * 1000);
        v1--;
        v2--;
        if (d[v1][v2] != INF && d[v1][v2] != dist){
            printf("NO");
            return 0;
        }
        d[v1][v2] = dist;
        d[v2][v1] = dist;
    }
    for (int k = 0; k < nV; k++) {
        for (int i = 0; i < nV; i++) {
            for (int j = 0; j < nV; j++) {
                if (d[i][k] < INF && d[k][j] < INF) { 
                    long long newDist = d[i][j];

                    if (i < k && k < j || j < k && k < i) {
                        newDist = d[i][k] + d[k][j]; 
                    } else if (i < j && j < k || k < j && j < i) { 
                        newDist = d[i][k] - d[k][j];
                    } else if (k < i && i < j || j < i && i < k) { 
                        newDist = d[k][j] - d[i][k];
                    }

                    if (d[i][j] < INF && d[i][j] != newDist || newDist < 0) {
                        printf("NO");
                        return 0;
                    }
                    d[i][j] = newDist;
                    d[j][i] = newDist;
                }
            }
        }
    }
    for (int i = 1; i < nV; i++) {
        if (d[i - 1][i] == INF || d[i - 1][i] < 0) {
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    for (int i = 1; i < nV; i++) {
        printf("%lld.%03lld ", d[i - 1][i] / 1000, d[i - 1][i] % 1000);
    }
    return 0;
}