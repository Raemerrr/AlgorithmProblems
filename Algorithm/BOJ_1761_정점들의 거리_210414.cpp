#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 10001;
int N, M, treeHeight;
vector<vector<int>> parent;
vector<int> depth;
vector<int> dist;
vector<vector<pair<int, int>>> nodes;

void make_tree(const int cur) {
	for (const pair<int, int>& d : nodes[cur]) {
		int Next = d.first;
		if (depth[Next] == -1)
		{
			depth[Next] = depth[cur] + 1;
			parent[Next][0] = cur;
			make_tree(Next);
		}
	}
}

void dfs(const int cur) {
	for (const pair<int, int>& d : nodes[cur]) {
		int Next = d.first;
		int Cost = d.second;
		if (dist[Next] == INF)
		{
			dist[Next] = Cost + dist[cur];
			dfs(Next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	treeHeight = (int)ceil(log2(N));
	parent.assign(N, vector<int>(treeHeight, -1));
	nodes.assign(N, vector<pair<int, int>>());
	depth.assign(N, -1);
	dist.assign(N, INF);
	for (int i = 0; i < N - 1; i++)
	{
		int a = 0, b = 0, cost = 0;
		cin >> a >> b >> cost; a--; b--;
		nodes[a].emplace_back(b, cost);
		nodes[b].emplace_back(a, cost);
	}
	//0번 노드를 루트 노드로 설정한 거리 구하기
	dist[0] = 0;
	dfs(0);
	// parent 배열 값 채우기
	depth[0] = 0;
	make_tree(0);
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
		int distA = dist[a];
		int distB = dist[b];
		if (depth[a] < depth[b])
		{
			swap(a, b);
		}
		int diff = depth[a] - depth[b];
		for (int j = 0; diff > 0; j++)
		{
			if (diff % 2 > 0)
			{
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
		//여기서 a는 LCA
		cout << (distA + distB - (2 * dist[a])) << "\n";
	}
	return 0;
}