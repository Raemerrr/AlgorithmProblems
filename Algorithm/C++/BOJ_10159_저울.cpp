#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 10000000;
vector<vector<int>> v;
vector<vector<int>> dp;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	dp = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		v[num1][num2] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j)
			{
				if (v[i][j] > 0)
				{
					dp[i][j] = v[i][j];
				}
				else
				{
					dp[i][j] = INF;
				}
			}
		}
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dp[i][k] != INF && dp[k][j] != INF)
				{
					dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int ans = 0;
		for (int j = 1; j <= N; j++)
		{
			//현재 지점과 상대 지점이 연결된 것이 없다면
			if (dp[i][j] == INF && dp[j][i] == INF)
			{
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}