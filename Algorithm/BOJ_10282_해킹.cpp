#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 100000000;
int a, b, s;
vector<vector<pair<int, int>>> v;

void dijkstra()
{
	vector<int> dist = vector<int>(a + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, s);
	dist[s] = 0;
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
	int cnt = 0;
	int maxDist = 0;
	for (const auto& d : dist)
	{
		if (d != INF)
		{
			cnt++;
			maxDist = (maxDist > d) ? maxDist : d;
		}
	}
	cout << cnt << " " << maxDist << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		cin >> a >> b >> s;
		v = vector<vector<pair<int, int>>>(a + 1, vector<pair<int, int>>());
		for (int i = 0; i < b; i++)
		{
			int num1 = 0, num2 = 0, cost = 0;
			cin >> num1 >> num2 >> cost;
			//num1 -> num2 가 아닌 num2 -> num1 의존성이라 표현한 것을 역으로
			v[num2].emplace_back(num1, cost);
		}
		dijkstra();
	}
	return 0;
}