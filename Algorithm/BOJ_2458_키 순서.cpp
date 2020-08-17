#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 10000000;
int N, M, ans;
vector<vector<int>> v;
vector<vector<int>> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	dp = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		//상대와 키를 비교한 표시
		v[num1][num2] = 1;
	}

	//dp 테이블 초기화
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

	//서로 간 거리 계산을 통해 비교가 가능한 사람 찾기
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

	//핵심
	for (int i = 1; i <= N; i++)
	{
		int cnt = 1;
		for (int j = 1; j <= N; j++)
		{
			//나를 연결하고 있다면
			if (dp[j][i] != INF && dp[j][i] != 0)
			{
				cnt++;
			}
			//내가 직접 연결되어 있다면
			else if (dp[i][j] != INF && dp[i][j] != 0)
			{
				cnt++;
			}
		}
		//모든 사람과 연결되어 있다면
		if (cnt == N)
		{
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}