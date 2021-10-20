#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 30001;
int N, M, treeHeight, ans;
vector<vector<int>> nodes;
vector<vector<int>> parent;
vector<int> depth;
vector<int> dist;

void make_tree(const int cur) {
	for (const int Next : nodes[cur])
	{
		if (depth[Next] == -1)
		{
			depth[Next] = depth[cur] + 1;
			parent[Next][0] = cur;
			make_tree(Next);
		}
	}
}

void dfs(const int cur) {
	for (const int Next : nodes[cur])
	{
		if (dist[Next] == INF)
		{
			dist[Next] = dist[cur] + 1;
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
	nodes.assign(N, vector<int>());
	depth.assign(N, -1);
	dist.assign(N, INF);
	for (int i = 0; i < N - 1; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b; a--; b--;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	//LCA 트리 생성
	depth[0] = 0;
	make_tree(0);

	//루트에서 각 노드까지의 거리 입력
	dist[0] = 0;
	dfs(0);
	//parent 설정
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
	//문제 상에서 주어진 시작 위치 '1' -> 0번 인덱스부터 시작 tempB 값 설정
	int tempA = 0, tempB = 0;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a = 0;
		cin >> a; a--; tempA = a;
		int b = tempB;
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
		ans += (dist[tempA] + dist[tempB] - (2 * dist[a]));
		tempB = tempA;
	}
	cout << ans << "\n";
	return 0;
}