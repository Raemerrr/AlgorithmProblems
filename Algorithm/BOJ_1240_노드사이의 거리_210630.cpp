#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int N, M;
vector<vector<int>> nodes, dp;

void floyd_warshall() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				dp[i][j] = ((nodes[i][j] > 0) ? nodes[i][j] : INF);
			}
		}
	}

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
	nodes.assign(N, vector<int>(N, 0));
	dp.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N - 1; i++)
	{
		int A = 0, B = 0, Cost = 0;
		cin >> A >> B >> Cost; A--, B--;
		nodes[A][B] = Cost;
		nodes[B][A] = Cost;
	}
	floyd_warshall();
	while (M--)
	{
		int A = 0, B = 0;
		cin >> A >> B; A--, B--;
		cout << dp[A][B] << "\n";
	}
	return 0;
}