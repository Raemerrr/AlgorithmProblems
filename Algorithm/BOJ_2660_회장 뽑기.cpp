#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int INF = 10000000;
vector<vector<int>> v;
vector<vector<int>> dp;
int N, M;
map<int, vector<int>> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	dp = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

	while (true)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		if (num1 == -1 && num2 == -1)
		{
			break;
		}
		//����� ����
		v[num1][num2] = 1;
		v[num2][num1] = 1;
	}

	//dp���̺� �ʱ�ȭ
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

	//dp���̺� �� �Է�
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

	//�� ����
	for (int i = 1; i <= N; i++)
	{
		int key = 0;
		//�� ������ ���� ���� ģ�� ����(?)�� key������ ��� map�� ��´�.
		for (int j = 1; j <= N; j++)
		{
			if (dp[i][j] != INF)
			{
				key = max(dp[i][j], key);
			}
		}
		m[key].push_back(i);
	}
	//���� ���� key ���� �ش� key�� �����ִ� ������ ��
	cout << (*m.begin()).first << " " << (*m.begin()).second.size() << "\n";
	//key�� ���� ���� �������� ����
	sort((*m.begin()).second.begin(), (*m.begin()).second.end());
	//key�� ���� ���� ���
	for (const auto& d : (*m.begin()).second)
	{
		cout << d << " ";
	}
	return 0;
}