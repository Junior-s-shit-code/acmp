#include <stdio.h>
#include <vector>
#include <algorithm>

struct Sensor {

	int i;

	int j;

	int dist;

	static Sensor read() {
		int i, j, dist;
		scanf("%d %d %d", &i, &j, &dist);
		return Sensor{ i,j, dist};
	}

	bool isIntersec(const Sensor &second) const{
		int di = i - second.i;
		int dj = j - second.j;
		return di * di + dj * dj <= (dist + second.dist) * (dist + second.dist);
	}
};

void dfs(const int v,
		 bool &left, bool &right,
		 bool &top, bool &bot,
		 const int sizeI, const int sizeJ,
		 const std::vector<Sensor> &sensors,
		 std::vector<bool> &was) {
	was[v] = true;
	if (sensors[v].isIntersec(Sensor{ 0, sensors[v].j, 0 })) {
		top = true;
	} 
	if (sensors[v].isIntersec(Sensor{ sizeI, sensors[v].j, 0 })) {
		bot = true;
	}
	if (sensors[v].isIntersec(Sensor{ sensors[v].i, 0, 0 })) {
		left = true;
	}
	if (sensors[v].isIntersec(Sensor{ sensors[v].i, sizeJ, 0 })) {
		right = true;
	}
	for (int i = 0; i < (int)was.size(); i++) {
		if (!was[i] && sensors[v].isIntersec(sensors[i])) {
			dfs(i, left, right, top, bot, sizeI, sizeJ, sensors, was);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int sizeI, sizeJ, nSensors;
	scanf("%d %d %d", &sizeI, &sizeJ, &nSensors);
	std::vector<Sensor> sensors(nSensors);
	std::vector<bool> was(nSensors, false);
	for (int i = 0; i < nSensors; i++) {
		sensors[i] = Sensor::read();
	}
	for (int i = 0; i < nSensors; i++) {
		if (!was[i]) {
			bool left = false, right = false;
			bool top = false, bot = false;
			dfs(i, left, right, top, bot, sizeI, sizeJ, sensors, was);
			if ((top || right) && (left || bot)) {
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
	return 0;
}