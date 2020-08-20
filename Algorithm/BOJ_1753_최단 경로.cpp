#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 10000000;
int V, E, start;

vector<vector<pair<int, int>>> nodes;
vector<int> dist;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	cin >> start;
	nodes = vector<vector<pair<int, int>>>(V + 1, vector<pair<int, int>>());
	dist = vector<int>(V + 1, INF);
	for (int i = 0; i < E; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		nodes[num1].emplace_back(num2, cost);
	}

	priority_queue<pair<int, int>> pq;
	pq.emplace(0, start);
	dist[start] = 0;
	while (!pq.empty())
	{
		//최소 힙 - 부호 변환 주의
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < nodes[cur].size(); i++)
		{
			int Next = nodes[cur][i].first;
			int nCost = nodes[cur][i].second;
			if (dist[Next] > cost + nCost)
			{
				dist[Next] = cost + nCost;
				//최소 힙 - 부호 변환 주의
				pq.emplace(-dist[Next], Next);
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] != INF)
		{
			cout << dist[i] << "\n";
		}
		else
		{
			cout << "INF\n";
		}
	}
	return 0;
}