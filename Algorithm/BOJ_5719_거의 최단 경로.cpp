/*
4 5
0 2
0 1 5
0 3 1
1 2 1
3 1 1
3 2 2

answer : -1

cost : 3
0->3->1->2
0->3->2

�� ��θ� ��� ���쵵��.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int INF = 1000000000;
int N, M, start_, end_;
vector<vector<pair<int, int>>> v;

void dijkstra()
{
	int minDist = -1;
	while (true)
	{
		//�ٽ� - �Ÿ��� �����ϸ� ���� �������� ������ �Բ� �����Ѵ�!!
		vector<pair<int, vector<vector<int>>>> dist = vector<pair<int, vector<vector<int>>>>(N + 1, pair<int, vector<vector<int>>>(INF, vector<vector<int>>()));
		priority_queue<pair<int, int>> pq;
		pq.emplace(0, start_);
		dist[start_] = pair<int, vector<vector<int>>>(0, vector<vector<int>>(1, vector<int>{start_}));

		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			for (int i = 0; i < v[cur].size(); i++)
			{
				int Next = v[cur][i].first;
				int nCost = v[cur][i].second;
				int sumCost = cost + nCost;
				//�ִ� �Ÿ� ����� ���� ���� ����ؾ���.
				if (dist[Next].first >= sumCost && sumCost != INF)
				{
					//���ο� �ִ� �Ÿ����
					if (dist[Next].first > sumCost)
					{
						//�ִ� �Ÿ� �� �Է�
						dist[Next].first = sumCost;
						//���� �������� �ִ� ��� ���� - ���� �� ����
						dist[Next].second = dist[cur].second;
						//���ο� �ִ� ����� �ڽ��� ��ȣ�� �ο�
						for (int d = 0; d < dist[Next].second.size(); d++)
						{
							dist[Next].second[d].push_back(Next);
						}
						//pq ����
						pq.emplace(-dist[Next].first, Next);
					}
					//���� �ִ� �Ÿ��� ���ٸ�
					else
					{
						//dist[cur].second ���� ��θ� Next���� ��� �߰�
						for (int d = 0; d < dist[cur].second.size(); d++)
						{
							dist[Next].second.push_back(dist[cur].second[d]);
						}
						//���� �ߺ� ���ɼ� ������, �ڽ��� ��ȣ�� ���ӵǾ� �� ���ɼ� ����.... �׷��� ��������.
						for (int d = 0; d < dist[Next].second.size(); d++)
						{
							dist[Next].second[d].push_back(Next);
						}
					}
				}
			}
		}
		//�������� �� �� ���� �����
		if (dist[end_].first == INF)
		{
			cout << "-1\n";
			break;
		}
		else
		{
			//ù ��° ����Ŭ (��, �ִ� ���)
			if (minDist == -1)
			{
				minDist = dist[end_].first;
				//�ִ� ��� �ı� - �̺κ��� map, set �ڷᱸ���� �� ȿ�������� ���� ����
				for (int i = 0; i < dist[end_].second.size(); i++)
				{
					for (int j = 0; j < dist[end_].second[i].size() - 1; j++)
					{
						int a = dist[end_].second[i][j];
						int b = dist[end_].second[i][j + 1];
						for (int z = 0; z < v[a].size(); z++)
						{
							if (v[a][z].first == b)
							{
								v[a][z].second = INF;
							}
						}
					}
				}
			}
			else
			{
				//��� �ı� �� �������� �� �� ���ٸ�
				if (dist[end_].first == INF)
				{
					cout << "-1\n";
					break;
				}
				//���� �ִ� ��� �� ���
				else
				{
					cout << dist[end_].first << "\n";
					break;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		int minDist = 0;
		cin >> N >> M;
		if (N == 0 && M == 0)
		{
			break;
		}
		cin >> start_ >> end_;
		v = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>());
		for (int i = 0; i < M; i++)
		{
			int num1 = 0, num2 = 0, cost = 0;
			cin >> num1 >> num2 >> cost;
			v[num1].emplace_back(num2, cost);
		}
		dijkstra();
	}
	return 0;
}