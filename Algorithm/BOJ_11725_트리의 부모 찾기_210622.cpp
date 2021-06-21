#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> nodes;
vector<int> depth;
vector<vector<int>> parent;

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
	cin.tie();
	cin >> N;
	int treeHeigt = (int)ceil(log2(N));
	parent.assign(N, vector<int>(treeHeigt, -1));
	nodes.assign(N, vector<int>());
	depth.assign(N, -1);
	for (int i = 0; i < N - 1; i++)
	{
		int num1 = 0, num2 = 0; cin >> num1 >> num2;
		nodes[--num1].push_back(--num2);
		nodes[num2].push_back(num1);
	}

	// 0번 노드로부터 각 노드까지의 깊이를 구한다.
	depth[0] = 0;
	make_tree(0);
	for (int i = 0; i < treeHeigt - 1; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (parent[j][i] != -1)
			{
				parent[j][i + 1] = parent[parent[j][i]][i];
			}
		}
	}

	//각 노드의 부모 노드 출력
	for (int i = 1; i < N; i++)
	{
		cout << parent[i][0] + 1 << "\n";
	}
	return 0;
}