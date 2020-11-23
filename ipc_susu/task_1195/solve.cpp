#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

enum struct State {

	SITTING,

	STANDING,

	OUT
};

struct Man {

	int sitExtra;

	State state;

	explicit Man(const int sitExtra)
		: sitExtra(sitExtra)
		, state(State::OUT) 
	{}

	struct Greater {

		bool operator()(const Man *left, const Man *right) {
			return left->sitExtra > right->sitExtra;
		}
	};

	struct Less {

		bool operator()(const Man *left, const Man *right) {
			return left->sitExtra < right->sitExtra;
		}
	};
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nMen, nPlaces, nStops;
	scanf("%d %d %d", &nMen, &nPlaces, &nStops);
	std::vector<Man> men;
	men.reserve(nMen);
	std::vector<std::vector<Man*>> menIn(1 + nStops);
	std::vector<std::vector<Man*>> menOut(1 + nStops);
	long long ans = 0;
	for (int i = 0; i < nMen; i++) {
		int sitP, standP, getIn, getOut;
		scanf("%d %d %d %d", &sitP, &standP, &getIn, &getOut);
		ans += 1LL * standP * (getOut - getIn);
		if (sitP > standP) {
			men.push_back(Man(sitP - standP));
			menIn[getIn].push_back(&men.back());
			menOut[getOut].push_back(&men.back());
		}
	}
	std::priority_queue<Man*, std::vector<Man*>, Man::Less> standing;
	std::priority_queue<Man*, std::vector<Man*>, Man::Greater> sitting;
	long long sittingSum = 0;
	int sittingCount = 0;

	for (int stop = 1; stop <= nStops; stop++) {
		for (Man *m : menOut[stop]) {
			if (m->state == State::SITTING) {
				m->state = State::OUT;
				sittingSum -= m->sitExtra;
				sittingCount--;
			} else {
				m->state = State::OUT;
			}
		}

		for (Man *m : menIn[stop]) {
			standing.push(m);
			m->state = State::STANDING;
		}

		while (sittingCount < nPlaces && !standing.empty()) {
			Man *m = standing.top();
			standing.pop();
			if (m->state == State::OUT) {
				continue;
			}
			m->state = State::SITTING;
			sitting.push(m);
			sittingCount++;
			sittingSum += m->sitExtra;
		}

		while (!sitting.empty() && !standing.empty() && sitting.top()->sitExtra < standing.top()->sitExtra) {
			if (sitting.top()->state == State::OUT) {
				sitting.pop();
				continue;
			}
			if (standing.top()->state == State::OUT) {
				standing.pop();
				continue;
			}
			Man *mSit = sitting.top();
			sitting.pop();
			Man *mStand = standing.top();
			standing.pop();
			sittingSum -= mSit->sitExtra;
			sittingSum += mStand->sitExtra;
			sitting.push(mStand);
			standing.push(mSit);
			mStand->state = State::SITTING;
			mSit->state = State::STANDING;
		}
		ans += sittingSum;
	} 
	printf("%lld", ans);
	return 0;
}