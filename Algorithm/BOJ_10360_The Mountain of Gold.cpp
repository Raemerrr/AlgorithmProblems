#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;
const int INF = 100000000;
map<pair<int, int>, int> nodes;
int N, M;
vector<int> dist;
set<int> cycles;
//map<pair<int, int>, bool> cycles;
vector<bool> visited;


//bool BFS()
//{
//	vector<vector<bool>> visited(N, vector<bool>(N, false));
//	queue<int> q;
//	q.emplace(0);
//	while (!q.empty())
//	{
//		int startPoint = q.front();
//		q.pop();
//		for (int endPoint = 0; endPoint < N; endPoint++)
//		{
//			pair<int, int>tempPos(startPoint, endPoint);
//			if (endPoint != startPoint && cycles.count(tempPos) && !visited[startPoint][endPoint])
//			{
//				visited[startPoint][endPoint] = true;
//				q.emplace(endPoint);
//				if (endPoint == 0)
//				{
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}


void DFS()
{
	visited = vector<bool>(N, false);
	queue<int> q;
	q.emplace(0);
	visited[0] = true;
	while (!q.empty())
	{
		int Cur = q.front();
		q.pop();
		for (int Next= 0; Next < N; Next++)
		{
			if (Cur !=Next && !visited[Next] && nodes.count(pair<int,int>(Cur,Next)))
			{
				visited[Next] = true;
				q.emplace(Next);
			}
		}
		
	}
}

string Solution()
{
	DFS();
	dist[0] = 0;
	for (int i = 1; i <= N; i++)
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
				if (i == N && visited[To])
				{
					return "possible";
				}
				dist[To] = dist[From] + Cost;
			}
		}
	}
	/*if (!cycles.empty())
	{
		for (const auto& startPoint : cycles)
		{
			if (startPoint != 0)
			{
				if (nodes.count(pair<int, int>(startPoint, 0))) { return "possible"; }
			}
		}
	}*/
	/*if (!cycles.empty() && BFS() && dist[0] < 0)
	{
		return "possible";
	}*/
	return "not possible";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		cin >> N >> M;
		nodes.clear();
		cycles.clear();
		dist = vector<int>(N, INF);
		for (int i = 0; i < M; i++)
		{
			pair<int, int> p(0, 0); int cost = 0;
			cin >> p.first >> p.second >> cost;
			if (!nodes.count(p))
			{
				nodes[p] = cost;
			}
			else
			{
				nodes[p] = nodes[p] < cost ? nodes[p] : cost;
			}
		}
		cout << "Case #" << t << ": " << Solution() << "\n";
	}
	return 0;
}