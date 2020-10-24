#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
const int INF = 100000000;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int start = 1;
	vector<vector<pair<int, int>>> v = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
	vector<int> dist = vector<int>(n + 1, INF);
	for (const auto& d : edge)
	{
		v[d[0]].emplace_back(d[1], 1);
		v[d[1]].emplace_back(d[0], 1);
	}
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.emplace(dist[start], start);
	while (!pq.empty())
	{
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
				pq.emplace(-dist[Next], Next);
			}
		}
	}
	map<int, vector<int>, greater<int>> m;
	for (int i = 1; i <= n; i++)
	{
		m[dist[i]].push_back(i);
	}
	answer = (*m.begin()).second.size();
	return answer;
}