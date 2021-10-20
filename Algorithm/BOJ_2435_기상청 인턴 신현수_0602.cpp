#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, answer;
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
	for (int i = 0; i < K; i++)
	{
		answer += v[i];
	}
	int s = 0, e = K, tempAns = answer;
	while (e < N)
	{
		tempAns -= v[s];
		tempAns += v[e];
		answer = max(answer, tempAns);
		s++, e++;
	}
	cout << answer << "\n";
	return 0;
}