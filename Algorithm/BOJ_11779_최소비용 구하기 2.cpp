#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100000000;
int N, M, start_, end_;
vector<vector<pair<int, int>>> v;

void dijkstra()
{
	//핵심 - 거리를 저장하며 이전 노드까지의 구간을 함께 저장한다!!
	vector<pair<int, vector<int>>> dist = vector<pair<int, vector<int>>>(N + 1, pair<int, vector<int>>(INF, vector<int>()));
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, start_);
	dist[start_] = pair<int, vector<int>>(0, vector<int>{ start_ });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int Next = v[cur][i].first;
			int nCost = v[cur][i].second;
			if (dist[Next].first > cost + nCost)
			{
				dist[Next].first = cost + nCost;
				//이전 노드까지의 기록을 담고
				dist[Next].second = dist[cur].second;
				//현재 노드를 기록한다.
				dist[Next].second.push_back(Next);
				pq.emplace(-dist[Next].first, Next);
			}
		}
	}
	cout << dist[end_].first << "\n";
	cout << dist[end_].second.size() << "\n";
	for (const auto& d : dist[end_].second) { cout << d << " "; }cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		v[num1].emplace_back(num2, cost);
	}
	cin >> start_ >> end_;
	dijkstra();
	return 0;
}