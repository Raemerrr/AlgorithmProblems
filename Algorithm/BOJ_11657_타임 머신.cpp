#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

const LL INF = 9223372036854775805;
int N, M;
vector<LL> dist;
map<pair<int, int>, LL> nodes;
map<pair<int, int>, bool> inputCheck;

void bellmanFord()
{
	bool flag = false;
	for (int i = 1; i < N; i++)
	{
		for (auto& d : nodes) 
		{
			int From = d.first.first;
			int To = d.first.second;
			int Cost = d.second;

			if (dist[From] == INF)
			{
				continue;
			}
			if (dist[To] > dist[From] + Cost)
			{
				dist[To] = dist[From] + Cost;
			}
		}
	}

	for (auto& d : nodes)
	{
		int From = d.first.first;
		int To = d.first.second;
		int Cost = d.second;

		if (dist[From] == INF)
		{
			continue;
		}
		if (dist[To] > dist[From] + Cost)
		{
			flag = true;
			break;
		}
	}

	if (flag)
	{
		cout << "-1\n";
	}
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == INF)
			{
				cout << "-1\n";
			}
			else
			{
				cout << dist[i] << "\n";
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	dist = vector<LL>(N + 1, INF);
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		if (!inputCheck[pair<int, int>(num1, num2)])
		{
			nodes[pair<int, int>(num1, num2)] = cost;
			inputCheck[pair<int, int>(num1, num2)] = true;
		}
		else
		{
			//기존 값과 비교
			int curVal = nodes[pair<int, int>(num1, num2)];
			nodes[pair<int, int>(num1, num2)] = curVal < cost ? curVal : cost;
		}
	}
	dist[1] = 0;
	bellmanFord();
	return 0;
}