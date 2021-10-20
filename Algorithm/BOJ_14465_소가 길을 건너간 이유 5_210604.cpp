#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, B;
vector<int> v;
vector<int> sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> B;
	v.assign(N, 1);
	sum.assign(N, 0);
	for (int i = 0; i < B; i++)
	{
		int num = 0; cin >> num; num--;
		v[num] = 0;
	}
	int s = 0, e = K, total = 0, answer = N;
	for (int i = 0; i < K; i++) total += v[i];
	while (e < N)
	{
		total -= v[s];
		total += v[e];
		answer = min(answer, K - total);
		s++;
		e++;
	}
	cout << answer << "\n";
	return 0;
}