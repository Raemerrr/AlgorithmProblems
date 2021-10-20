#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

const ll INF = 987654321987654213;
int N, start_, end_, M;
map<pair<int, int>, ll> nodes;
map<pair<int, int>, bool> inputCheck;
vector<ll> dist;
vector<ll> maximum;
set<int> cycles;

void bellmanFord()
{
	dist[start_] = maximum[start_];
	for (int i = 1; i <= N; i++)
	{
		for (auto d : nodes)
		{
			int from = d.first.first;
			int to = d.first.second;
			int cost = d.second;

			if (dist[from] == INF)
			{
				continue;
			}
			if (dist[to] > dist[from] + cost + maximum[to])
			{
				if (i == N)
				{
					cycles.insert(from);
				}
				else
				{
					dist[to] = dist[from] + cost + maximum[to];
				}
			}
		}
	}
	//현재까지의 최적의 답 저장
	vector<ll> ans = dist;
	if (ans[end_] == INF)
	{
		cout << "gg\n";
		return;
	}

	for (const auto& d : cycles)
	{
		dist = vector<ll>(N, INF);
		dist[d] = maximum[d];
		for (int i = 1; i < N; i++)
		{
			for (auto d : nodes)
			{
				int from = d.first.first;
				int to = d.first.second;
				int cost = d.second;

				if (dist[from] == INF)
				{
					continue;
				}
				if (dist[to] > dist[from] + cost + maximum[to])
				{
					dist[to] = dist[from] + cost + maximum[to];
				}
			}
		}
		if (dist[end_] != INF)
		{
			cout << "Gee\n";
			return;
		}
	}
	//음수 처리 했던 값을 다시 부호를 바꿔 준다.
	cout << -ans[end_] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> start_ >> end_ >> M;
	dist = vector<ll>(N, INF);
	maximum = vector<ll>(N, 0);
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		if (!inputCheck[pair<int, int>(num1, num2)])
		{
			nodes[pair<int, int>(num1, num2)] = cost;
			inputCheck[pair<int, int>(num1, num2)] = true;
		}
		else
		{
			int tCost = nodes[pair<int, int>(num1, num2)];
			nodes[pair<int, int>(num1, num2)] = tCost < cost ? tCost : cost;
		}
	}
	//최대 얻을 수 있는 값을 음수 처리 
	//양의 사이클을 찾는 문제라 음의 사이클 로직을 태우기 위해.
	//음수 처리를 함으로써 계속 얻을 수 있는 돈이 사이클(무제한)을 도는지 확인.
	for (int i = 0; i < N; i++)
	{
		cin >> maximum[i];
		maximum[i] *= -1;
	}
	bellmanFord();
	return 0;
}