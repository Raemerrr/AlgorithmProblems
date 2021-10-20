#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, answer;
vector<vector<int>> nodes;
vector<bool> visited;

void bfs(const int Start) {
	visited[Start] = true;
	queue<int> q;
	q.push(Start);
	while (!q.empty())
	{
		int front = q.front(); q.pop();
		for (const int Next : nodes[front]) {
			if (!visited[Next])
			{
				visited[Next] = true;
				q.push(Next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	nodes.assign(N, vector<int>());
	visited.assign(N, false);
	while (M--)
	{
		int u = 0, v = 0; cin >> u >> v; u--, v--;
		nodes[u].push_back(v);
		nodes[v].push_back(u);
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			bfs(i);
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}