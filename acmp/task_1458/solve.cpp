#include <stdio.h>
#include <vector>
#include <algorithm>

struct Edge {

    int vSum; // compression verticies

    bool isBridge;
};

void findBridges(
    const int curV,
    const int &parent,
    int &timer,
    std::vector<int> &time,
    std::vector<int> &minTime,
    std::vector<std::vector<Edge *>> &neigh
) {
    time[curV] = timer;
    minTime[curV] = timer;
    timer++;
    for (Edge *e : neigh[curV]) {
        int nextV = e->vSum - curV;
        if (nextV == parent) {
            continue;
        }
        if (time[nextV] == -1) {
            findBridges(nextV, curV, timer, time, minTime, neigh);
            if (time[curV] < minTime[nextV]) {
                e->isBridge = true;
            }
            minTime[curV] = std::min(minTime[curV], minTime[nextV]);
        } else {
            minTime[curV] = std::min(minTime[curV], time[nextV]);
        }
    }
}

void visit(
    const int curV,
    int &sizeBigVertex,
    int &nBridges,
    std::vector<bool> &was,
    std::vector<std::vector<Edge *>> &neigh
) {
    was[curV] = true;
    sizeBigVertex++;
    for (const Edge *e : neigh[curV]) {
        if (e->isBridge) {
            nBridges++;
        } else {
            int nextV = e->vSum - curV;
            if (!was[nextV]) {
                visit(nextV, sizeBigVertex, nBridges, was, neigh);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MOD = (int)1e9 + 7;
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<Edge> edges(nE, Edge{ 0, false });
    std::vector<std::vector<Edge *>> neigh(1 + nV);
    for (Edge &e : edges) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        e.vSum = v1 + v2;
        neigh[v1].push_back(&e);
        neigh[v2].push_back(&e);
    }

    int timer = 0;
    std::vector<int> time(1 + nV, -1);
    std::vector<int> minTime(1 + nV, -1);
    findBridges(1, 0, timer, time, minTime, neigh);

    std::vector<bool> was(1 + nV, false);
    int countOptions = 0;
    int prod = 1;
    for (int i = 1; i <= nV; i++) {
        if (!was[i]) {
            int size = 0;
            int nBridges = 0;
            visit(i, size, nBridges, was, neigh);
            if (nBridges <= 1) {
                prod = (int)(1LL * prod * size % MOD);
                countOptions++;
            }
        }
    }

    printf("%d %d", countOptions, prod);
    return 0;
}