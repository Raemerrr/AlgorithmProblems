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
	//�ʱ� �� �Է�
	for (int i = 0; i < K; i++)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		v[num1][num2] = 1;
	}

	//dp���̺� �ʱ�ȭ
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

	//���� ���� ���� ����
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
			//�ڿ� �ִ� ��ȣ�� ����� ���� �Ͼ� ����.
			if (dp[num2][num1] != INF)
			{
				cout << "1\n";
			}
			//�� ���� ���� ���� ����.
			else
			{
				cout << "0\n";
			}
		}
		//�տ� �ִ� ��ȣ�� ����� ���� �Ͼ� ����.
		else
		{
			cout << "-1\n";
		}
	}
	return 0;
}