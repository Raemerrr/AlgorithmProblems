#include <iostream>
#include <vector>

using namespace std;

int N, M, R, ans, tempAns;
//각 노드의 아이템 수
vector<int> items;
//각 노드의 연결과 해당 거리를 담는 변수
vector<vector<pair<int, int>>> node;
//방문했던 여부를 담는 변수
vector<bool> visited;

void DFS(const int currNode, const int preNode, const int dist)
{
	//왔던길 되돌아가는 것 방지(무한 루프 방지..)
	if (currNode == preNode)
	{
		return;
	}
	for (int i = 0; i < node[currNode].size(); i++)
	{
		int nextNode = node[currNode][i].first;
		int nextDist = node[currNode][i].second;
		if (dist + nextDist <= M)
		{
			if (!visited[nextNode])
			{
				visited[nextNode] = true;
				tempAns += items[nextNode];
			}
			DFS(nextNode, currNode, dist + nextDist);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> R;
	node = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	items = vector<int>(N + 1, 0);
	visited = vector<bool>(N + 1, false);
	for (int i = 1; i <= N; i++)
	{
		cin >> items[i];
	}
	for (int i = 0; i < R; i++)
	{
		int num1 = 0, num2 = 0, dist = 0;
		cin >> num1 >> num2 >> dist;
		node[num1].emplace_back(num2, dist);
		node[num2].emplace_back(num1, dist);
	}
	for (int i = 1; i <= N; i++)
	{
		visited[i] = true;
		tempAns = items[i];
		DFS(i, -1, 0);
		visited = vector<bool>(N + 1, false);
		ans = (ans > tempAns) ? ans : tempAns;
	}
	cout << ans << "\n";
	return 0;
}