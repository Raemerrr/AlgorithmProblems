#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100000000;
int N, M;
vector<vector<pair<int, int>>> v;
vector<vector<int>> ans;

void dijkstra()
{
	//1�� ������ �� �湮���� ���� ��θ� �ľ��Ѵ�.
	for (int start_ = 1; start_ <= N; start_++)
	{
		priority_queue<pair<int, int>> pq;
		pq.emplace(0, start_);
		vector<pair<int, vector<int>>> dist = vector<pair<int, vector<int>>>(N + 1, pair<int, vector<int>>{ INF, vector<int>() });
		dist[start_] = { 0, vector<int>{start_} };
		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			for (const auto& d : v[cur])
			{
				int Next = d.first;
				int nCost = d.second;
				int sumCost = cost + nCost;
				if (dist[Next].first > sumCost)
				{
					//�ִ� �Ÿ���� ���� �湮 ����� ���� �湮������ �ѱ�
					dist[Next].second = dist[cur].second;
					//���� �湮 ��Ͽ� ���� ��� ��ȣ �߰�
					dist[Next].second.push_back(Next);
					dist[Next].first = sumCost;
					pq.emplace(-dist[Next].first, Next);
				}
			}
		}

		for (int i = 1; i <= N; i++)
		{
			if (i != start_)
			{
				//�� ������ ���� ���� ����̸�
				//������ ��� ���� ��尡 �ִ� �Ÿ��� ������ �湮�ؾ� �� ���
				ans[i][start_] = dist[i].second[dist[i].second.size() - 2];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>(N + 1, pair<int, int>()));
	ans = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		//����� ����!
		v[num1].emplace_back(num2, cost);
		v[num2].emplace_back(num1, cost);
	}
	dijkstra();
	//���� ���
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (ans[i][j] == 0)
			{
				cout << "- ";
			}
			else
			{
				cout << ans[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}