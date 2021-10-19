#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 10000000;
int N, M, start = 1;
//���� ��忡�� ����� ���� ���� ���
vector<vector<pair<int, int>>> v;
//������ ���, ���� ��� ��ȣ
vector<pair<int, int>> dist;
vector<pair<int, int>> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	//���� ū ������ �ʱ�ȭ
	dist = vector<pair<int, int>>(N + 1, pair<int, int>(INF, 0));
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		v[num1].emplace_back(num2, cost);
		v[num2].emplace_back(num1, cost);
	}

	priority_queue<pair<int, int>> pq;
	//������ 1�� ������ǻ�� ����
	pq.emplace(0, start);
	//���� �Ÿ��� 0���� ����
	dist[start].first = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int Next = v[cur][i].first;
			int nCost = v[cur][i].second;
			//���� ������ ������� �湮�ߴٸ�
			if (dist[Next].first > cost + nCost)
			{
				//������ ��� ����
				dist[Next].first = cost + nCost;
				//���� �湮 ��� ����
				dist[Next].second = cur;
				pq.emplace(-dist[Next].first, Next);
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		//���� �� �� ���� ��ǻ�ʹ� ����
		if (dist[i].first != INF)
		{
			ans.emplace_back(i, dist[i].second);
		}
	}
	cout << ans.size() << "\n";
	for (const auto& d : ans)
	{
		cout << d.first << " " << d.second << "\n";
	}
	return 0;
}