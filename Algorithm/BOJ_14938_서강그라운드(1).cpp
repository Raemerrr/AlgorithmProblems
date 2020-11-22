#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int INF = 100000000;
int n, m, r;
//map<int, int> answer;
int answer;
vector<vector<int>> v;
vector<vector<int>> dist;
vector<int> items;

void Proc()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				if (v[i][j] > 0)
				{
					dist[i][j] = v[i][j];
				}
				else
				{
					dist[i][j] = INF;
				}
			}
		}
	}
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

	for (int i = 1; i <= n; i++)
	{
		int tAnswer = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] <= m)
			{
				tAnswer += items[j];
			}
		}
		answer = (answer > tAnswer) ? answer : tAnswer;
	}
	cout << answer << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> r;
	v = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	dist = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	items = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> items[i];
	}
	for (int i = 0; i < r; i++)
	{
		int a = 0, b = 0, cost = 0;
		cin >> a >> b >> cost;
		v[a][b] = cost;
		v[b][a] = cost;
	}
	Proc();
	return 0;
}