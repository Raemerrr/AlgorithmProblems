#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 100000000;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<int>> nodes = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> dist = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	//node 연결
	for (const auto& d : results)
	{
		nodes[d[0]][d[1]] = 1;
	}
	//연결 접점이 없는 곳은 INF처리
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				if (nodes[i][j] > 0)
				{
					dist[i][j] = nodes[i][j];
				}
				else
				{
					dist[i][j] = INF;
				}
			}
		}
	}
	//플로이드-와샬 알고리즘 이용
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][k] != INF && dist[k][j] != INF)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
	//얻어낸 결과를 이용해 단방향으로 연결되어있다면 양방향 값을 입력해준다.
	//ex) 1번이 2번을 이긴다. 2번 입장에서는 1번에게 지는 것이기때문에 지는 값도 입력해주는 의미!
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				if (dist[i][j] != INF)
				{
					dist[j][i] = dist[i][j];
				}
			}
		}
	}
	//자기 자신 노드를 제외하고 나머지 모두와 연결되어 있다면 순위를 알 수 있는 노드.
	for (int i = 1; i <= n; i++)
	{
		bool flag = true;
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				if (dist[i][j] == INF)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag) { answer++; }
	}
	return answer;
}