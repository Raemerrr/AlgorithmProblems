#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100000000;
int N, M, K, X;
vector<vector<pair<int, int>>> nodes;
vector<int> dist;

vector<int> Solution()
{
	vector<int> answer;
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, X);
	dist[X] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (const auto& d : nodes[cur])
		{
			int Next = d.first;
			int nCost = d.second;
			if (dist[Next] > cost + nCost)
			{
				dist[Next] = cost + nCost;
				pq.emplace(-dist[Next], Next);
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == K)
		{
			answer.push_back(i);
		}
	}

	if (answer.empty())
	{
		answer.push_back(-1);
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K >> X;
	nodes = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	dist = vector<int>(N + 1, INF);
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		nodes[num1].emplace_back(pair<int, int>(num2, 1));
	}
	for (const auto& d : Solution())
	{
		cout << d << "\n";
	}
	return 0;
}