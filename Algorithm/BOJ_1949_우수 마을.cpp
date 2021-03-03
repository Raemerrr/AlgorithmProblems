#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, Start = 1;
vector<int> cost;
vector<vector<int>> v;
vector<bool> visited;
vector<vector<int>> dp;

void bfs() {
	vector<vector<int>> og = v;
	v.assign(N + 1, vector<int>());
	queue<int> q;
	q.push(Start);
	visited[Start] = true;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		for (const auto& d : og[front]) {
			if (!visited[d])
			{
				visited[d] = true;
				q.push(d);
				v[front].push_back(d);
			}
		}
	}
}

int solution(const int cur, bool flag) {
	if (dp[cur][flag] != -1) {
		return dp[cur][flag];
	}
	//우수마을이라면
	if (flag)
	{
		dp[cur][flag] = cost[cur];
		for (const auto& d : v[cur]) {
			dp[cur][flag] += solution(d, false);
		}
	}
	else
	{
		dp[cur][flag] = 0;
		for (const auto& d : v[cur]) {
			dp[cur][flag] += max(solution(d, true), solution(d, false));
		}
	}
	return dp[cur][flag];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cost.assign(N + 1, 0);
	visited.assign(N + 1, false);
	v.assign(N + 1, vector<int>());
	dp.assign(N + 1, vector<int>(2, -1));
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
	}
	int a = 0, b = 0;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	cout << max(solution(1, true), solution(1, false)) << "\n";
	return 0;
}