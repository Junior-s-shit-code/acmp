#include <stdio.h>
#include <algorithm>
#include <vector>

struct Info {

    int power;

    int cost;

    static Info read() {
        int power, cost;
        scanf("%d %d", &power, &cost);
        return Info{ power,cost };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nRooms;
    scanf("%d", &nRooms);
    std::vector<int> minPower(nRooms);
    for (int i = 0; i < nRooms; i++) {
        scanf("%d", &minPower[i]);
    }
    std::sort(minPower.begin(), minPower.end());
    int nConditioners;
    scanf("%d", &nConditioners);
    std::vector<Info> conditioners(nConditioners);
    for (int i = 0; i < nConditioners; i++) {
        conditioners[i] = Info::read();
    }
    std::sort(conditioners.begin(), conditioners.end(), [](const Info &left, const Info &right) {
        if (left.cost != right.cost) {
            return left.cost < right.cost;
        } 
        return left.power > right.power;
    });
    std::vector<Info> options;
    int maxPower = 0;
    for (int i = 0; i < nConditioners; i++) {
        if (conditioners[i].power > maxPower) {
            maxPower = conditioners[i].power;
            options.push_back(conditioners[i]);
        }
    }
    int id = 0;
    int sumCost = 0;
    for (int i = 0; i < nRooms; i++) {
        while (options[id].power < minPower[i]) {
            id++;
        }
        sumCost += options[id].cost;
    }
    printf("%d", sumCost);
    return 0;
}