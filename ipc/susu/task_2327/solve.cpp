#include <stdio.h>
#include <vector>
#include <algorithm>

struct Component {

	int cost;

	int rate;

	int id;
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nComponents, nTypes, maxSum;
	scanf("%d %d", &nTypes, &nComponents);
	std::vector<std::vector<Component>> types(nTypes);
	for (int i = 0; i < nComponents; i++) {
		int cost, rate, type;
		scanf("%d %d %d", &cost, &rate, &type);
		types[type - 1].push_back(Component{ cost, rate, i + 1});
	}
	scanf("%d", &maxSum);
	std::vector<std::vector<int>> countBestRate(nTypes + 1, std::vector<int>(maxSum + 1, -1));
	for (int i = 0; i < maxSum; i++) {
		countBestRate[0][i] = 0;
	}
	std::vector<std::vector<int>> usedComponent(nTypes + 1, std::vector<int>(maxSum + 1));
	for (int iType = 0; iType < nTypes; iType++) {
		for (int sum = 0; sum < maxSum; sum++) {
			for (int iComponent = 0; iComponent < (int)types[iType].size(); iComponent++) {
				if (iType == 0 || countBestRate[iType][sum] != 0) {
					int nextSum = sum + types[iType][iComponent].cost;
					if (nextSum <= maxSum && 
						countBestRate[iType + 1][nextSum] <
						countBestRate[iType][sum] + types[iType][iComponent].rate
						) {
						countBestRate[iType + 1][nextSum] = countBestRate[iType][sum] + types[iType][iComponent].rate;
						usedComponent[iType + 1][nextSum] = iComponent;
					}
				}
			}
		}
	}
	int bestRate = -1;
	int ansSum = -1;
	for (int i = 0; i <= maxSum; i++) {
		if (bestRate < countBestRate[nTypes][i]) {
			bestRate = countBestRate[nTypes][i];
			ansSum = i;
		}
	}
	std::vector<int> ans(nTypes);
	printf("%d\n", bestRate);
	if (bestRate != -1) {
		for (int iType = nTypes; iType > 0; iType--) {
			int iComponent = usedComponent[iType][ansSum];
			ans[iType - 1] = types[iType - 1][iComponent].id;
			ansSum -= types[iType - 1][iComponent].cost;
		}
		for (int i = 0; i < nTypes; i++) {
			printf("%d ", ans[i]);
		}
	}
	return 0; 
}