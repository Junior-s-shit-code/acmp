#include <stdio.h>
#include <vector>
#include <algorithm>

struct Coin {

	int cost;

	int weight;

	static Coin read() {
		int cost, weight;
		scanf("%d %d", &cost, &weight);
		return Coin{ cost, weight };
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int freeWeight, maxWeight;
	scanf("%d %d", &freeWeight, &maxWeight);
	int weight = maxWeight - freeWeight;
	int nCoins;
	scanf("%d", &nCoins);
	std::vector<Coin> coins(nCoins);
	for (int i = 0; i < nCoins; i++) {
		coins[i] = Coin::read();
	}
	const int INF = (int)1e9;
	std::vector<int> maxCost(weight + 1, 0);
	std::vector<int> minCost(weight + 1, INF);
	minCost[0] = 0;
	for (int iWeight = 0; iWeight <= weight; iWeight++) {
		if (minCost[iWeight] != INF) {
			for (int iCoin = 0; iCoin < nCoins; iCoin++) {
				int newInd = iWeight + coins[iCoin].weight;
				if (newInd <= weight) {
					minCost[newInd] = std::min(minCost[newInd], minCost[iWeight] + coins[iCoin].cost);
					maxCost[newInd] = std::max(maxCost[newInd], maxCost[iWeight] + coins[iCoin].cost);
				}
			}
		}
	}

	if (minCost[weight] == INF) {
		printf("This is impossible.");
	} else {
		printf("%d %d", minCost[weight], maxCost[weight]);
	}
	return 0;
}