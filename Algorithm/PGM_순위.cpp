#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 100000000;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<int>> nodes = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> dist = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	//node ����
	for (const auto& d : results)
	{
		nodes[d[0]][d[1]] = 1;
	}
	//���� ������ ���� ���� INFó��
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				if (nodes[i][j] > 0)
				{
					dist[i][j] = nodes[i][j];
				}
				else
				{
					dist[i][j] = INF;
				}
			}
		}
	}
	//�÷��̵�-�ͼ� �˰��� �̿�
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][k] != INF && dist[k][j] != INF)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
	//�� ����� �̿��� �ܹ������� ����Ǿ��ִٸ� ����� ���� �Է����ش�.
	//ex) 1���� 2���� �̱��. 2�� ���忡���� 1������ ���� ���̱⶧���� ���� ���� �Է����ִ� �ǹ�!
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				if (dist[i][j] != INF)
				{
					dist[j][i] = dist[i][j];
				}
			}
		}
	}
	//�ڱ� �ڽ� ��带 �����ϰ� ������ ��ο� ����Ǿ� �ִٸ� ������ �� �� �ִ� ���.
	for (int i = 1; i <= n; i++)
	{
		bool flag = true;
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				if (dist[i][j] == INF)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag) { answer++; }
	}
	return answer;
}