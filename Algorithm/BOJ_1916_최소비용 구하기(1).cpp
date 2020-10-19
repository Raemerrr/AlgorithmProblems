#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100000000;

int N, M, s, e;
vector<vector<pair<int, int>>> v;
vector<int> dist;

void dijkstra()
{
	priority_queue<pair<int, int>> q;
	q.emplace(0, s);
	dist[s] = 0;
	while (!q.empty())
	{
		int cost = -q.top().first;
		int cur = q.top().second;
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int Next = v[cur][i].first;
			int nCost = v[cur][i].second;
			if (dist[Next] > cost + nCost)
			{
				dist[Next] = cost + nCost;
				q.emplace(-dist[Next], Next);
			}
		}
	}
	cout << dist[e] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	dist = vector<int>(N + 1, INF);
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		v[num1].emplace_back(num2, cost);
	}
	cin >> s >> e;
	dijkstra();
	return 0;
}