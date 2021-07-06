#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

const int INF = 100000000;
int N, M;
vector<int> dist;
map<pair<int, int>, int> m;

string solution() {
	dist[0] = 0;
	set<int> cycle;
	for (int i = 0; i <= N; i++)
	{
		for (const auto& d : m) {
			int from = d.first.first;
			int to = d.first.second;
			int cost = d.second;
			if (dist[from] == INF)
			{
				continue;
			}
			if (dist[to] > dist[from] + cost)
			{
				if (i == N)
				{
					cycle.insert(to);
					cycle.insert(from);
				}
				dist[to] = dist[from] + cost;
			}
		}
	}
	if (!cycle.empty())
	{
		for (const auto& z : cycle)
		{
			dist.assign(N, INF);
			dist[z] = 0;
			for (int i = 0; i < N; i++)
			{
				for (const auto& d : m) {
					int from = d.first.first;
					int to = d.first.second;
					int cost = d.second;
					if (dist[from] == INF)
					{
						continue;
					}
					if (dist[to] > dist[from] + cost)
					{
						dist[to] = dist[from] + cost;
					}
				}
			}
			if (dist[0] != INF)
			{
				return ": possible\n";
			}
		}
			
	}
	return ": not possible\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		cin >> N >> M;
		dist.assign(N, INF);
		m.clear();
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b >> c;
			if (m.count({a,b}))
			{
				m[{a, b}] = (c < m[{a, b}]) ? c : m[{a, b}];
			}
			else
			{
				m[{a, b}] = c;
			}
		}
		cout << "Case #" << t << solution();
	}
	return 0;
}