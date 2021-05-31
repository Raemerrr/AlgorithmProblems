#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, answer = -987654321;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	v.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	int s = 0, e = K, sum = 0;
	for (int i = 0; i < K; i++)
	{
		sum += v[i];
	}
	answer = max(answer, sum);
	while (e < N)
	{
		sum -= v[s];
		sum += v[e];
		answer = max(answer, sum);
		s++;
		e++;
	}
	cout << answer << "\n";
	return 0;
}