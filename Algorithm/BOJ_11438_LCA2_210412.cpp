#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> nodes;
vector<vector<int>> parent;
vector<int> depth;

void makeTree(const int cur) {
	for (const int Next : nodes[cur])
	{
		if (depth[Next] == -1)
		{
			parent[Next][0] = cur;
			depth[Next] = depth[cur] + 1;
			makeTree(Next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int treeHeight = (int)ceil(log2(N));
	nodes.assign(N, vector<int>());
	parent.assign(N, vector<int>(treeHeight, -1));
	depth.assign(N, -1);
	for (int i = 0; i < N - 1; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b; a--; b--;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	depth[0] = 0;
	makeTree(0);
	for (int i = 0; i < treeHeight - 1; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (parent[j][i] != -1)
			{
				parent[j][i + 1] = parent[parent[j][i]][i];
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b; a--; b--;
		if (depth[a] < depth[b])
		{
			swap(a, b);
		}
		int diff = depth[a] - depth[b];
		for (int j = 0; diff; j++)
		{
			if (diff % 2) {
				a = parent[a][j];
			}
			diff /= 2;
		}
		if (a != b)
		{
			for (int j = treeHeight - 1; j >= 0; j--)
			{
				if (parent[a][j] != -1 && parent[a][j] != parent[b][j])
				{
					a = parent[a][j];
					b = parent[b][j];
				}
			}
			a = parent[a][0];
		}
		cout << a + 1 << "\n";
	}
	return 0;
}