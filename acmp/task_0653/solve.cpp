#include <stdio.h>
#include <vector>
#include <algorithm>

struct Info {

    char c;

    int first;

    int second;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<int>> a(sizeI, std::vector<int>(sizeJ));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    // fill vectors with info
    std::vector<int> height(sizeI);
    for (int i = 0; i < sizeI; i++) {
        height[i] = (a[i][0] - 1) / sizeJ;
    }
    std::vector<int> width(sizeJ);
    int min = (int)1e8;
    for (int j = 0; j < sizeJ; j++) {
        width[j] = a[0][j];
        min = std::min(min, width[j]);
    }
    for (int j = 0; j < sizeJ; j++) {
        width[j] -= min;
    }
    // algo
    std::vector<Info> ans;
    for (int i = 0; i < sizeI; i++) {
        while (height[i] != i) {
            int swapId = height[i];
            ans.push_back(Info{ 'R', i + 1, swapId + 1 });
            std::swap(height[i], height[swapId]);
        }
    }
    for (int j = 0; j < sizeJ; j++) {
        while (width[j] != j) {
            int swapId = width[j];
            ans.push_back(Info{ 'C', j + 1, swapId + 1 });
            std::swap(width[j], width[swapId]);
        }
    }
    printf("%d\n", (int)ans.size());
    for (const Info &item : ans) {
        printf("%c %d %d\n", item.c, std::min(item.first, item.second), std::max(item.first, item.second));
    }
    return 0;
}