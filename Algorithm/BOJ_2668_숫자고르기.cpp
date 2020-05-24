#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> visited;
vector<int> v;
vector<int> ans;

//위상 정렬
void dfs(const int startNode, const int currentNode)
{
	if (visited[currentNode])
	{
		if (startNode == currentNode)
		{
			ans.emplace_back(startNode);
		}
	}
	else
	{
		visited[currentNode] = true;
		dfs(startNode, v[currentNode]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	visited = vector<bool>(N + 1, false);
	v = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= N; i++)
	{
		dfs(i, i);
		visited = vector<bool>(N + 1, false);
	}
	cout << ans.size() << "\n";
	for (auto& d : ans) { cout << d << "\n"; }
	return 0;
}