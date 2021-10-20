#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 200000000;
int N, M, X, ans;
vector<vector<int>> v;
vector<vector<int>> dp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> X;
	v = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	dp = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	//단방향 입력
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		v[num1][num2] = cost;
	}

	//dp 테이블 세팅
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

	//단방향으로 가장 가까운 거리로 도달 할 수 있는 경우 구하기
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

	//출발과 돌아오는 값을 더해서 가장 큰 값을 구한다.
	for (int i = 1; i <= N; i++)
	{
		ans = max(dp[i][X] + dp[X][i], ans);
	}
	cout << ans << "\n";
	return 0;
}