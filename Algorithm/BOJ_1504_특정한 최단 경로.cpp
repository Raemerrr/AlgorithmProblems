/*
����� -> �߰� 1 -> �߰� 2 -> ������
����� -> �߰� 2 -> �߰� 1 -> ������
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
	//��� 1 : ����� -> �߰� 1 -> �߰� 2 -> ������
	route[0] = vector<pair<int, int>>{ pair<int,int>(1,target[0]),pair<int,int>(target[0],target[1]),pair<int,int>(target[1],N) };
	//��� 2 : ����� -> �߰� 2 -> �߰� 1 -> ������
	route[1] = vector<pair<int, int>>{ pair<int,int>(1,target[1]),pair<int,int>(target[1],target[0]),pair<int,int>(target[0],N) };
	/*
		for���� ���� ��� �湮 �� �湮 �� �� ���� ��찡 ����ٸ� INF(�ִ�)�� �ִ´�.
		��� �������� �ʰ� �ٸ� ��ηδ� �湮�� �������� Ȯ���Ѵ�.
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