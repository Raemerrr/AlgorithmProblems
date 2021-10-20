#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, INF = 987654321;
vector<vector<int>> nodes;
vector<vector<int>> dp;

void floyd_warshall() {
	// dp배열 초기화
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				dp[i][j] = (nodes[i][j] != INF) ? nodes[i][j] : INF;
			}
		}
	}
	// 각 노드간 거리 구하기
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (dp[i][k] != INF && dp[k][j] != INF)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	nodes.assign(N, vector<int>(N, INF));
	dp.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N - 1; i++)
	{
		int a = 0, b = 0, c = 0; cin >> a >> b >> c; a--, b--;
		nodes[a][b] = c;
		nodes[b][a] = c;
	}

	floyd_warshall();
	while (M--)
	{
		int a = 0, b = 0; cin >> a >> b; a--, b--;
		cout << dp[a][b] << "\n";
	}
	return 0;
}