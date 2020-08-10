/*

�÷��̵� ���� �˰���
 ��� �������� �� �������� �ִ� �Ÿ��� ���ϴ� �˰���...

//���� �Է�
5
1 2 4
2 3 3
6 3 2
5 3 1
3 4 5
*/

#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 

using namespace std;

const int INF = 987654321;
int dp[100][100];
int edge[100][100];
int N;

int main(void)
{
	cin >> N;
	// �׷��� ��� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
	{
		int num1 = 0, num2 = 0, dist = 0;
		cin >> num1 >> num2 >> dist;
		edge[num1][num2] = dist;
		edge[num2][num1] = dist;
	}
	// �׷��� ��� �ʱ�ȭ (N + 1�� ������ �������� ������ 1�� �� ���� ����)
	for (int i = 1; i <= N + 1; i++)
	{
		for (int t = 1; t <= N + 1; t++)
		{
			if (i == t) { dp[i][t] = 0; }
			else if (edge[i][t] > 0) { dp[i][t] = edge[i][t]; }
			else { dp[i][t] = INF; }
		}
	}

	// ������ 1 ~ N + 1���� ��ȸ (N + 1�� ������ �������� ������ 1�� �� ���� ����)
	for (int k = 1; k <= N + 1; ++k)
	{
		for (int i = 1; i <= N + 1; ++i)
		{
			for (int j = 1; j <= N + 1; ++j)
			{
				if (dp[i][k] != INF && dp[k][j] != INF)
				{
					dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
				}
			}
		}
	}

	for (int i = 1; i <= N + 1; ++i)
	{
		cout << "dp[" << i << "] : ";
		for (int j = 1; j <= N + 1; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}