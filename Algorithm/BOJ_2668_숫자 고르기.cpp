#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<bool> visited;
vector<int> ans;

void Proc(const int startNode, const int currNode)
{
	if (startNode == currNode)
	{
		ans.push_back(startNode);
	}
	else
	{
		if (!visited[currNode])
		{
			visited[currNode] = true;
			Proc(startNode, v[currNode]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<int>(N + 1, 0);
	visited = vector<bool>(N + 1, false);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= N; i++)
	{
		Proc(i, v[i]);
		visited = vector<bool>(N + 1, false);
	}
	cout << ans.size() << "\n";
	for (const auto& d : ans) { cout << d << "\n"; }
	return 0;
}