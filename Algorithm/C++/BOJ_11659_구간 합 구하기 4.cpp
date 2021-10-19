#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
vector<int> dp;
vector<pair<int, int>> range;

void Proc()
{
	int answer = 0;
	for (const auto& d : range)
	{
		answer = (d.first <= 1) ? dp[d.second - 1] : dp[d.second - 1] - dp[d.first - 2];
		cout << answer << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<int>(N, 0);
	dp = vector<int>(N, 0);
	range = vector<pair<int, int>>(M, pair<int, int>(0, 0));
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> range[i].first >> range[i].second;
	}
	dp[0] = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		dp[i] = dp[i - 1] + v[i];
	}
	Proc();
	return 0;
}