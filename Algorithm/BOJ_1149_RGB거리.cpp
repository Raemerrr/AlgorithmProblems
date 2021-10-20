#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<int>> dp;

void Proc()
{
	dp[1][1] = map[1][1];
	dp[1][2] = map[1][2];
	dp[1][3] = map[1][3];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (j == 1)
			{
				dp[i][j] = min(dp[i - 1][2], dp[i - 1][3]) + map[i][j];
			}
			else if (j == 2)
			{
				dp[i][j] = min(dp[i - 1][1], dp[i - 1][3]) + map[i][j];
			}
			else
			{
				dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + map[i][j];
			}
		}
	}
	cout << min(min(dp[N][1], dp[N][2]), dp[N][3]) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	map = vector<vector<int>>(N + 1, vector<int>(3 + 1, 0));
	dp = vector<vector<int>>(N + 1, vector<int>(3 + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> map[i][j];
		}
	}
	Proc();
	return 0;
}