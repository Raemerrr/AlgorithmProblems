#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//임의의 트리 루트 고정 값
const int Start = 0;
int N, M, treeHeight;
vector<vector<int>> nodes, parent;
vector<int> depth;

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

void make_tree(const int Cur) {
	for (const int Next : nodes[Cur]) {
		if (depth[Next] == -1)
		{
			depth[Next] = depth[Cur] + 1;
			parent[Next][0] = Cur;
			make_tree(Next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	treeHeight = (int)ceil(log2(N));
	parent.assign(N, vector<int>(treeHeight, -1));
	nodes.assign(N, vector<int>());
	depth.assign(N, -1);
	for (int i = 0; i < N - 1; i++)
	{
		int a = 0, b = 0; cin >> a >> b; a--, b--;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	depth[Start] = 0;
	make_tree(Start);
	////parent 설정
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
		int r = 0, u = 0, v = 0; cin >> r >> u >> v; r--, u--, v--;
		vector<pair<int, int>> arr;
		//r과 u의 LCA
		int a = find_LCA(r, u);
		arr.emplace_back(a, depth[a]);
		//r과 v의 LCA
		int b = find_LCA(r, v);
		arr.emplace_back(b, depth[b]);
		//u와 v의 LCA
		int c = find_LCA(u, v);
		arr.emplace_back(c, depth[c]);
		//3개 중 depth가 가장 깊은 값
		sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
			if (a.second == b.second) return a.first < b.first;
			return a.second < b.second;
			});
		cout << arr.back().first + 1 << "\n";
	}
	return 0;
}