#include <stdio.h>
#include <algorithm>
#include <vector>

struct Edge {

    int from;

    int to;

    int cost;

    static Edge read() {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        return Edge{ from - 1, to - 1, cost };
    }
};

void dfs(int v, std::vector<bool> &was, std::vector<std::vector<int>> &g) {
    was[v] = true;
    for (int nextV : g[v]) {
        if (!was[nextV]) {
            dfs(nextV, was, g);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector <Edge> e(nE);
    for (int i = 0; i < nE; i++) {
        e[i] = Edge::read();
    }
    
    std::vector<bool> used(nV, false);
    std::vector<int> curComb(nE, 0);
    for (int i = 0; i < nV - 1; i++) {
        curComb[i] = 1;
    }
    std::vector<std::vector<int>> g(nV);
    int bestCost = (int)1e9;
    std::vector<int> bestComb(nE);
    while (true) {
        for (std::vector<int> &edge : g) {
            edge.clear();
        }
        used.assign(nV, false);
        int curCost = 0;
        for (int i = 0; i < nE; i++) {
            if (curComb[i] == 1) {
                curCost += e[i].cost;
                g[e[i].from].push_back(e[i].to);
            }
        }
        dfs(0, used, g);
        bool isGood = true;
        for (int i = 0; i < nV; i++) {
            isGood &= used[i];
        }
        if (isGood && curCost < bestCost) {
            bestCost = curCost;
            bestComb = curComb;
        }
        int changeIndex = -1;
        for (int i = nE - 2; i >= 0; i--) {
            if (curComb[i] == 1 && curComb[i + 1] == 0) {
                changeIndex = i;
                break;
            }
        }
        if (changeIndex == -1) {
            break;
        }
        int countOnes = 0;
        for (int i = changeIndex; i < nE; i++) {
            countOnes += curComb[i];
            curComb[i] = 0;
        }
        for (int i = changeIndex + 1; i <= changeIndex + countOnes; i++) {
            curComb[i] = 1;
        }
    }
    printf("%d %d\n", bestCost, nV - 1);
    for (int i = 0; i < nE; i++) {
        if (bestComb[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    return 0;
}