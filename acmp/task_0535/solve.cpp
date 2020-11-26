#include <stdio.h>
#include <string>
#include <set>

long long getSum(long long num1, long long num2) {
	std::string ans = "";
	while (num1 + num2 > 0) {
		int sum = num1 % 10 + num2 % 10;
		ans = std::to_string(sum) + ans;
		num1 /= 10;
		num2 /= 10;
	}
	return std::atoll(ans.c_str());
}

long long getTripleSum(long long num1, long long num2, long long num3) {
	return getSum(getSum(num1, num2), num3);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	std::set<long long> ans;
	ans.insert(getTripleSum(a, b, c));
	ans.insert(getTripleSum(a, c, b));
	ans.insert(getTripleSum(b, c, a));
	printf((int)ans.size() == 1 ? "NO\n" : "YES\n");
	for (long long item : ans) {
		printf("%lld\n", item);
	}
	return 0;
}