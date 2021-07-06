#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, treeHeight, Root = 0;
vector<vector<int>> node, parent;
vector<int> depth;

void make_tree(const int Cur) {
	for (const int Next : node[Cur])
	{
		if (depth[Next] == -1)
		{
			depth[Next] = depth[Cur] + 1;
			parent[Next][0] = Cur;
			make_tree(Next);
		}
	}
}

int find_LCA(int a, int b) {
	if (depth[a] < depth[b])
	{
		swap(a, b);
	}
	int diff = depth[a] - depth[b];
	for (int i = 0; diff > 0; i++)
	{
		if (diff % 2 > 0)
		{
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
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		a = parent[a][0];
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	treeHeight = (int)ceil(log2(N));
	node.assign(N, vector<int>());
	parent.assign(N, vector<int>(treeHeight, -1));
	depth.assign(N, -1);
	for (int i = 0; i < N - 1; i++)
	{
		int a = 0, b = 0; cin >> a >> b; a--, b--;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	depth[Root] = 0;
	make_tree(Root);

	for (int j = 0; j < treeHeight - 1; j++)
	{
		for (int i = 1; i < N; i++)
		{
			if (parent[i][j] != -1)
			{
				parent[i][j + 1] = parent[parent[i][j]][j];
			}
		}
	}

	cin >> M;
	while (M--)
	{
		int a = 0, b = 0; cin >> a >> b; a--, b--;
		cout << find_LCA(a, b) + 1 << "\n";
	}
	return 0;
}