#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long LL;

const LL INF = 9223372036854775805;

int N, M;
vector<LL> dist;
map<pair<int, int>, LL> nodes;
void bellmanFord()
{
	//문제에서 주어진 시작점은 1
	dist[1] = 0;
	bool flag = false;
	for (int i = 0; i <= N; i++)
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
				if (i == N)
				{
					flag = true;
					break;
				}
				dist[To] = dist[From] + Cost;
			}
		}
	}
	//정답 출력부
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
	cin >> N >> M;
	dist = vector<LL>(N + 1, INF);
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		pair<int, int> node(num1, num2);
		//기존에 입력받은 적이 있다면
		if (nodes.count(node))
		{
			nodes[node] = nodes[node] < cost ? nodes[node] : cost;
		}
		//기존에 입력받은 적이 없다면
		else
		{
			nodes[node] = cost;
		}
	}
	bellmanFord();
	return 0;
}