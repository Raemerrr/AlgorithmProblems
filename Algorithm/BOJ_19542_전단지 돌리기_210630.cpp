#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, D, answer;
vector<vector<int>> nodes;
vector<int> depth;
vector<bool> visited;

void dfs(const int Cur) {
	for (const int Next : nodes[Cur])
	{
		if (!visited[Next])
		{
			visited[Next] = true;
			dfs(Next);
			depth[Cur] = max(depth[Cur], depth[Next] + 1);
		}
	}
}

void search(const int Cur) {
	for (const int Next : nodes[Cur])
	{
		if (!visited[Next] && depth[Next] >= D)
		{
			visited[Next] = true;
			answer++;
			search(Next);
			answer++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> S >> D; S--;
	nodes.assign(N, vector<int>());
	depth.assign(N, 0);
	for (int i = 0; i < N - 1; i++)
	{
		int A = 0, B = 0; cin >> A >> B; A--, B--;
		nodes[A].push_back(B);
		nodes[B].push_back(A);
	}
	visited.assign(N, false);
	visited[S] = true;
	dfs(S);

	visited.assign(N, false);
	visited[S] = true;
	search(S);
	cout << answer << "\n";
	return 0;
}