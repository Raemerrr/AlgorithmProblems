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
//map<pair<int, int>, int> m;
vector<vector<int>> v;

string solution() {
	dist[0] = 0;
	set<int> cycle;
	for (int i = 0; i <= N; i++)
	{
		for (int from = 0; from < N; from++)
		{
			for (int to = 0; to < N; to++)
			{
				if (from != to)
				{
					if (dist[from] == INF)
					{
						continue;
					}
					int cost = v[from][to];
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
		}
		//for (const auto& d : m) {
		//	int from = d.first.first;
		//	int to = d.first.second;
		//	int cost = d.second;
		//	if (dist[from] == INF)
		//	{
		//		continue;
		//	}
		//	if (dist[to] > dist[from] + cost)
		//	{
		//		if (i == N)
		//		{
		//			cycle.insert(to);
		//			cycle.insert(from);
		//		}
		//		dist[to] = dist[from] + cost;
		//	}
		//}
	}
	if (!cycle.empty())
	{
		vector<vector<int>> dp(N, vector<int>(N, 0));
		for (const auto& z : cycle) {
			dist.assign(N, 0);
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (i != j)
					{
						dp[i][j] = (v[i][j] != INF) ? v[i][j] : INF;
					}
				}
			}

			for (int k = 0; k < N; k++)
			{
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
					}
				}
			}
			if (dp[z][0] != INF)
			{
				return ": possible\n";
			}
			//dist.assign(N, INF);
			//dist[z] = 0;
			//for (int i = 0; i < N; i++)
			//{
			//	for (const auto& d : m) {
			//		int from = d.first.first;
			//		int to = d.first.second;
			//		int cost = d.second;
			//		if (dist[from] == INF)
			//		{
			//			continue;
			//		}
			//		if (dist[to] > dist[from] + cost)
			//		{
			//			dist[to] = dist[from] + cost;
			//		}
			//	}
			//}
			//if (dist[0] != INF)
			//{
			//	return ": possible\n";
			//}
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
		v.assign(N, vector<int>(N, INF));
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b >> c;
			v[a][b] = (c < v[a][b]) ? c : v[a][b];
			//if (m.count({a,b}))
			//{
			//	m[{a, b}] = (c < m[{a, b}]) ? c : m[{a, b}];
			//}
			//else
			//{
			//	m[{a, b}] = c;
			//}
		}
		////음수 전환
		//for (auto& d : m) {
		//	d.second *= -1;
		//}
		std::cout << "Case #" << t << solution();
	}
	return 0;
}