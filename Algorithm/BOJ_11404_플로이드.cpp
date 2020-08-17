#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000000;
int N, nodeCnt;
vector<vector<int>> v;
vector<vector<int>> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> nodeCnt;
	v = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	dp = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < nodeCnt; i++)
	{
		int a = 0, b = 0, cost = 0;
		cin >> a >> b >> cost;
		//문제에서 말하는 "시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다." 비용이 적은 노선만 생각하기위해
		if (v[a][b] != 0)
		{
			v[a][b] = min(v[a][b], cost);
		}
		else
		{
			v[a][b] = cost;
		}
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
		for (int j = 1; j <= N; j++)
		{
			//도착 할 수 없는 곳
			if (dp[i][j] == INF)
			{
				cout << "0 ";
			}
			else
			{
				cout << dp[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}