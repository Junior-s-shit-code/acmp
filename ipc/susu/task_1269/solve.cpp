#include <stdio.h>
#include <vector>

struct Animal {

    int x;

    int y;

    static Animal read() {
        int x, y;
        scanf("%d %d", &x, &y);
        return Animal{ x ,y };
    }

    int distTo(const Animal &second) const{
        int dx = x - second.x;
        int dy = y - second.y;
        return dx * dx + dy * dy;
    }
};

void dfs(int v, const int &dist, std::vector<bool> &was, const std::vector<Animal> &a) {
    Animal cur = a[v];
    was[v] = true;
    for (int i = 0; i < (int)a.size(); i++) {
        if (!was[i] && cur.distTo(a[i]) <= dist) {
            dfs(i, dist, was, a);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nAnimals, dist;
    scanf("%d %d", &nAnimals, &dist);
    std::vector<Animal> a(nAnimals);
    std::vector<bool> isInHerd(nAnimals, false);
    int ans = 0;
    for (int i = 0; i < nAnimals; i++) {
        a[i] = Animal::read();
    }
    for (int i = 0; i < nAnimals; i++) {
        if (!isInHerd[i]) {
            ans++;
            dfs(i, dist * dist, isInHerd, a);
        }
    }
    printf("%d", ans);
    return 0;
}