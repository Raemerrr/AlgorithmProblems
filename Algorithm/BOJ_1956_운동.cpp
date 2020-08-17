#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 10000000;
int V, E;
int ans = INF;
vector<vector<int>> v;
vector<vector<int>> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	v = vector<vector<int>>(V + 1, vector<int>(V + 1, 0));
	dp = vector<vector<int>>(V + 1, vector<int>(V + 1, 0));
	for (int i = 0; i < E; i++)
	{
		int num1 = 0, num2 = 0, dist = 0;
		cin >> num1 >> num2 >> dist;
		v[num1][num2] = dist;
	}

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
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

	for (int k = 1; k <= V; k++)
	{
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (dp[i][k] != INF && dp[k][j] != INF)
				{
					dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
				}
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		int dist = INF;
		for (int j = 1; j <= V; j++)
		{
			if (i != j)
			{
				dist = min(dp[i][j] + dp[j][i], dist);
			}
		}
		ans = min(dist, ans);
	}

	//최단 경로가 없는 경우
	if (ans == INF)
	{
		cout << "-1\n";
	}
	else
	{
		cout << ans << "\n";
	}
	return 0;
}