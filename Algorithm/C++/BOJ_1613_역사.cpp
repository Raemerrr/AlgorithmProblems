#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 30000000;
int N, K, S, ans;
vector<vector<int>> v;
vector<vector<int>> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	v = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	dp = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	//초기 값 입력
	for (int i = 0; i < K; i++)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		v[num1][num2] = 1;
	}

	//dp테이블 초기화
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (j != i)
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

	//서로 연결 관계 정리
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

	cin >> S;
	for (int i = 0; i < S; i++)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		if (dp[num1][num2] == INF)
		{
			//뒤에 있는 번호의 사건이 먼저 일어 났다.
			if (dp[num2][num1] != INF)
			{
				cout << "1\n";
			}
			//둘 간의 연결 고리가 없다.
			else
			{
				cout << "0\n";
			}
		}
		//앞에 있는 번호의 사건이 먼저 일어 났다.
		else
		{
			cout << "-1\n";
		}
	}
	return 0;
}