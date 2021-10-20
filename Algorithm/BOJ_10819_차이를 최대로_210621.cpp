#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer = -987654321;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	do {
		int sum = 0;
		for (int i = 0; i < N - 1; i++) sum += abs(v[i] - v[i + 1]);
		answer = max(answer, sum);
	} while (next_permutation(v.begin(), v.end()));
	cout << answer << "\n";
	return 0;
}