#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	const int INF = 987654321;
	int answer = INF;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	vector<vector<int>> node(n, vector<int>(n, 0));
	for (const vector<int>& d : fares) {
		//����� ����
		node[d[0] - 1][d[1] - 1] = d[2];
		node[d[1] - 1][d[0] - 1] = d[2];
	}
	//dp �ʱ�ȭ
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				dp[i][j] = (node[i][j] > 0) ? node[i][j] : INF;
			}
		}
	}
	//�÷��̵�-�ͼ� : �� ���� �� �ִ� �Ÿ� ���ϱ� 
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dp[i][k] != INF && dp[k][j] != INF)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
	}
	//���� �������� A�� B�� ���� ���� �ִ� ��� : ���� Ÿ�� ���� ��� ���ϱ� (���� Ư�� ��.. ������ ���ǹ�..)
	answer = (dp[s - 1][b - 1] < INF && dp[s - 1][a - 1] < INF) ? dp[s - 1][b - 1] + dp[s - 1][a - 1] : INF;
	//���� ������ ������ �߰� �������� �ս� �� ���� ���� ��� ���ϱ�
	for (int i = 0; i < n; i++)
	{
		//���� ���� ����, �߰� �������� A�� B�� �ϳ��� �� �� ���ٸ� ����
		if (i == s - 1 || dp[s - 1][i] >= INF || dp[i][b - 1] >= INF || dp[i][a - 1] >= INF) continue;
		//���� ���� -> �߰� ����(i)������ �Ÿ� + �߰� ����(i) -> B���� + �߰� ����(i) -> A���� ��� ���ϱ�
		answer = min((dp[s - 1][i] + dp[i][b - 1] + dp[i][a - 1]), answer);
	}
	return answer;
}

int main() {
	// case : 1
	//int n = 6, s = 4, a = 6, b = 2;
	//vector<vector<int>> fares{ {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} };
	// case : 2
	int n = 7, s = 3, a = 4, b = 1;
	vector<vector<int>> fares{ {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6} };
	cout << solution(n, s, a, b, fares) << "\n";
	return 0;
}