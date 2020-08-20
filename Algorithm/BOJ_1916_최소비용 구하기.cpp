#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 200000000;
int N, M, s, e;
vector<vector<pair<int, int>>> v;
vector<int> dist;

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

	priority_queue<pair<int, int>> pq;
	pq.emplace(0, s);
	dist[s] = 0;
	while (!pq.empty())
	{
		//최소 힙 음수 적용 -
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int Next = v[cur][i].first;
			int nCost = v[cur][i].second;
			if (dist[Next] > cost + nCost)
			{
				dist[Next] = cost + nCost;
				//최소 힙 음수 적용 -
				pq.emplace(-dist[Next], Next);
			}
		}
	}
	//정답 도출
	cout << dist[e] << "\n";
	return 0;
}