#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1000001;
int N, M, treeHeight;
vector<vector<pair<int, int>>> node;
vector<vector<int>> parent;
vector<int> depth;
vector<vector<pair<int, int>>> dist;

void make_tree(const int Cur) {
	for (const pair<int, int>& d : node[Cur]) {
		int Next = d.first, Cost = d.second;
		if (depth[Next] == -1)
		{
			depth[Next] = depth[Cur] + 1;
			parent[Next][0] = Cur;
			dist[Next][0] = { Cost, Cost };
			make_tree(Next);
		}
	}
}

void find_LCA(int a, int b) {
	int mini = INF, maxi = -1;
	if (depth[a] < depth[b])
	{
		swap(a, b);
	}
	int diff = depth[a] - depth[b];
	for (int i = 0; diff > 0; i++)
	{
		if (diff % 2 > 0)
		{
			mini = min(mini, dist[a][i].first);
			maxi = max(maxi, dist[a][i].second);
			a = parent[a][i];
		}
		diff /= 2;
	}
	if (a != b)
	{
		for (int i = treeHeight - 1; i >= 0; i--)
		{
			if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
			{
				mini = min(mini, dist[a][i].first);
				maxi = max(maxi, dist[a][i].second);
				a = parent[a][i];

				mini = min(mini, dist[b][i].first);
				maxi = max(maxi, dist[b][i].second);
				b = parent[b][i];
			}
		}
		mini = min(mini, dist[a][0].first);
		maxi = max(maxi, dist[a][0].second);
		mini = min(mini, dist[b][0].first);
		maxi = max(maxi, dist[b][0].second);
		a = parent[a][0];
	}
	cout << mini << " " << maxi << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	treeHeight = (int)ceil(log2(N));
	node.assign(N, vector<pair<int, int>>());
	parent.assign(N, vector<int>(treeHeight, -1));
	depth.assign(N, -1);
	dist.assign(N, vector<pair<int, int>>(treeHeight, { INF, -1 }));
	for (int i = 0; i < N - 1; i++)
	{
		int a = 0, b = 0, c = 0; cin >> a >> b >> c; a--, b--;
		node[a].emplace_back(b, c);
		node[b].emplace_back(a, c);
	}
	depth[0] = 0;
	make_tree(0);

	for (int j = 0; j < treeHeight - 1; j++)
	{
		for (int i = 1; i < N; i++)
		{
			int Father = parent[i][j];
			if (Father != -1)
			{
				parent[i][j + 1] = parent[Father][j];
				dist[i][j + 1].first = min(dist[i][j].first, dist[Father][j].first);
				dist[i][j + 1].second = max(dist[i][j].second, dist[Father][j].second);
			}
		}
	}

	cin >> M;
	while (M--)
	{
		int a = 0, b = 0; cin >> a >> b; a--, b--;
		find_LCA(a, b);
	}
	return 0;
}