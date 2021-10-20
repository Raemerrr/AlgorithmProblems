#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 100000000;
int N, M, K, start_ = 1;
vector<vector<pair<int, int>>> v;

void dijkstra()
{
	vector<priority_queue<int>> dist = vector<priority_queue<int>>(N + 1, priority_queue<int>());
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, start_);
	dist[start_].push(0);
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
			//최단 거리 큐에 K개가 들어갈때까지
			if (dist[Next].size() < K)
			{
				dist[Next].push(sumCost);
				pq.emplace(-sumCost, Next);
			}
			//최단 거리 구하기
			else if (dist[Next].top() > sumCost)
			{
				dist[Next].pop();
				dist[Next].push(sumCost);
				pq.emplace(-sumCost, Next);
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (dist[i].size() == K)
		{
			cout << dist[i].top() << "\n";
		}
		else
		{
			cout << "-1\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	v = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		v[num1].emplace_back(num2, cost);
	}
	dijkstra();
	return 0;
}