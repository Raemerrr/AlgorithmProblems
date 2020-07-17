#include <iostream>
#include <vector>

using namespace std;

int N, cnt;
//방문 제한을 위한 변수
vector<bool> check;
//탐색을 할 때 마다 재 방문 여부를 판단하는 변수
vector<bool> visited;
//데이터를 담아 놓은 변수
vector<int> v;

void Proc(const int startNode, const int currentNode)
{
	//사이클을 도는 중 이미 방문한 적이 있었다면,
	if (visited[currentNode])
	{
		cnt++;
		//현재까지 탐색 구간 중 사이클을 이루는 곳 카운트
		int temp = v[currentNode];
		while (temp != currentNode)
		{
			cnt++;
			temp = v[temp];
		}
	}
	else
	{
		visited[currentNode] = true;
		if (!check[v[currentNode]])
		{
			Proc(startNode, v[currentNode]);
			//한번 방문한 곳은 다시 방문하지 않도록.
			check[currentNode] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		cin >> N;
		visited = vector<bool>(N + 1, false);
		check = vector<bool>(N + 1, false);
		v = vector<int>(N + 1, 0);
		cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			cin >> v[i];
		}
		for (int i = 1; i <= N; i++)
		{
			if (!check[i])
			{
				visited = vector<bool>(N + 1, false);
				Proc(i, i);
			}
		}
		cout << v.size() - cnt - 1 << "\n";
	}
	return 0;
}