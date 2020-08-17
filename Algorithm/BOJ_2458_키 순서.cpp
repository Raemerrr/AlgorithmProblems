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
		//���� Ű�� ���� ǥ��
		v[num1][num2] = 1;
	}

	//dp ���̺� �ʱ�ȭ
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

	//���� �� �Ÿ� ����� ���� �񱳰� ������ ��� ã��
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

	//�ٽ�
	for (int i = 1; i <= N; i++)
	{
		int cnt = 1;
		for (int j = 1; j <= N; j++)
		{
			//���� �����ϰ� �ִٸ�
			if (dp[j][i] != INF && dp[j][i] != 0)
			{
				cnt++;
			}
			//���� ���� ����Ǿ� �ִٸ�
			else if (dp[i][j] != INF && dp[i][j] != 0)
			{
				cnt++;
			}
		}
		//��� ����� ����Ǿ� �ִٸ�
		if (cnt == N)
		{
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}