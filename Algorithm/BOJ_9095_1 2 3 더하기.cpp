#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<vector<int>> dp;
vector<vector<int>> map;

void Func()
{
	dp[1][1] = map[1][1];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			//좌측 끝일 경우
			if (j == 1)
			{
				dp[i][j] = dp[i - 1][j] + map[i][j];
			}
			//우측 끝일 경우
			else if (j == i)
			{
				dp[i][j] = dp[i - 1][j - 1] + map[i][j];
			}
			//중간에 있는 경우
			else
			{
				//dp[i - 1][j] + map[i][j] : 우 상단에서 내려온 경우
				//dp[i - 1][j - 1] + map[i][j] : 좌 상단에서 내려온 경우
				dp[i][j] = (dp[i - 1][j] + map[i][j] > dp[i - 1][j - 1] + map[i][j]) ? dp[i - 1][j] + map[i][j] : dp[i - 1][j - 1] + map[i][j];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	dp = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> map[i][j];
		}
	}
	Func();
	//마지막 노드에서 가장 큰 값 찾기
	for (int i = 1; i <= N; i++)
	{
		ans = (ans > dp[N][i]) ? ans : dp[N][i];
	}
	cout << ans << "\n";
	return 0;
}