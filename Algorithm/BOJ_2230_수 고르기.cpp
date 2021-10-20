#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, s, e, answer;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	answer = 2100000000;
	v = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	while (s < N && e < N)
	{
		if (v[e] - v[s] < M)
		{
			e++;
		}
		else
		{
			answer = min(answer, v[e] - v[s]);
			s++;
		}
	}
	cout << answer << "\n";
	return 0;
}