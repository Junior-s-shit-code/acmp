#include <stdio.h>
#include <vector>
#include <queue>

struct Edge {

    int v1;

    int v2;

    static Edge read() {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        return Edge{ v1 - 1, v2 - 1 };
    }
};

void paint(
    int curV,
    int &ans,
    const int nV,
    const int nColors,
    const int nE,
    const std::vector<Edge> &edges,
    std::vector<int> &colors
) {
    if (curV == nV) {
        bool ok = true;
        for (int iE = 0; iE < nE; iE++) {
            if (colors[edges[iE].v1] == colors[edges[iE].v2]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    } else {
        for (int iColor = 0; iColor < nColors; iColor++) {
            colors[curV] = iColor;
            paint(curV + 1, ans, nV, nColors, nE, edges, colors);
        }
    }
    
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nV, nColors, nE;
    scanf("%d %d %d", &nV, &nColors, &nE);
    std::vector<Edge> edges(nE);
    for (int i = 0; i < nE; i++) {
        edges[i] = Edge::read();
    }
    std::vector<int> colors(nV);
    int ans = 0;
    paint(0, ans, nV, nColors, nE, edges, colors);
    printf("%d", ans);
    return 0;
}
