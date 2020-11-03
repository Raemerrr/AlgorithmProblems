#include <iostream>
#include <vector>
using namespace std;

int N, M, s, e, sum, answer;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	while (true)
	{
		if (sum >= M)
		{
			sum -= v[s++];
		}
		else if (e == N)
		{
			break;
		}
		else
		{
			sum += v[e++];
		}
		if (sum == M)
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}