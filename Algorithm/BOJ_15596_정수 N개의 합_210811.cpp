#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
	for (const int d : a) { ans += d; }
	return ans;
}
