#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 100000000;
int N, M, s, e;
vector<vector<pair<int, int>>> v;
vector<int> dist;

void solution() {
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, s);
	dist[s] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (const auto& d : v[cur]) {
			int Next = d.first;
			int cCost = d.second;
			if (dist[Next] > cost + cCost)
			{
				dist[Next] = cost + cCost;
				pq.emplace(-dist[Next], Next);
			}
		}
	}
	cout << dist[e];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v.assign(N + 1, vector<pair<int, int>>());
	dist.assign(N + 1, INF);
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v[a].emplace_back(b, c);
		v[b].emplace_back(a, c);
	}
	cin >> s >> e;
	solution();
	return 0;
}