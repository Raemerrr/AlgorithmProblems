/*
출발지 -> 중간 1 -> 중간 2 -> 도착지
출발지 -> 중간 2 -> 중간 1 -> 도착지
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 10000000;
int N, E;
vector<vector<pair<int, int>>> v;
vector<int> dist;
vector<int> target;
vector<int> ans;
vector<vector<pair<int, int>>> route;
priority_queue<pair<int, int>> pq;

int dijkstra(const int _start, const int _end)
{
	dist = vector<int>(N + 1, INF);
	pq.emplace(0, _start);
	dist[_start] = 0;
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
	return dist[_end];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> E;
	v = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	target = vector<int>(2, 0);
	ans = vector<int>(2, 0);
	route = vector<vector<pair<int, int>>>(2, vector<pair<int, int>>());
	for (int i = 0; i < E; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		v[num1].emplace_back(num2, cost);
		v[num2].emplace_back(num1, cost);
	}
	cin >> target[0] >> target[1];
	//경로 1 : 출발지 -> 중간 1 -> 중간 2 -> 도착지
	route[0] = vector<pair<int, int>>{ pair<int,int>(1,target[0]),pair<int,int>(target[0],target[1]),pair<int,int>(target[1],N) };
	//경로 2 : 출발지 -> 중간 2 -> 중간 1 -> 도착지
	route[1] = vector<pair<int, int>>{ pair<int,int>(1,target[1]),pair<int,int>(target[1],target[0]),pair<int,int>(target[0],N) };
	/*
		for문을 돌며 경로 방문 중 방문 할 수 없는 경우가 생긴다면 INF(최댓값)을 넣는다.
		즉시 종료하지 않고 다른 경로로는 방문이 가능한지 확인한다.
	*/
	for (int i = 0; i < route.size(); i++)
	{
		for (int j = 0; j < route[i].size(); j++)
		{
			int cost = dijkstra(route[i][j].first, route[i][j].second);
			if (cost == INF)
			{
				ans[i] = INF;
				break;
			}
			ans[i] += cost;
		}
	}
	sort(ans.begin(), ans.end());
	if (ans[0] == INF)
	{
		cout << "-1\n";
	}
	else
	{
		cout << ans[0] << "\n";
	}
	return 0;
}