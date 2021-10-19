/*
4 5
0 2
0 1 5
0 3 1
1 2 1
3 1 1
3 2 2

answer : -1

cost : 3
0->3->1->2
0->3->2

두 경로를 모두 지우도록.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int INF = 1000000000;
int N, M, start_, end_;
vector<vector<pair<int, int>>> v;

void dijkstra()
{
	int minDist = -1;
	while (true)
	{
		//핵심 - 거리를 저장하며 이전 노드까지의 구간을 함께 저장한다!!
		vector<pair<int, vector<vector<int>>>> dist = vector<pair<int, vector<vector<int>>>>(N + 1, pair<int, vector<vector<int>>>(INF, vector<vector<int>>()));
		priority_queue<pair<int, int>> pq;
		pq.emplace(0, start_);
		dist[start_] = pair<int, vector<vector<int>>>(0, vector<vector<int>>(1, vector<int>{start_}));

		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			for (int i = 0; i < v[cur].size(); i++)
			{
				int Next = v[cur][i].first;
				int nCost = v[cur][i].second;
				int sumCost = cost + nCost;
				//최단 거리 비용이 같을 때도 고려해야함.
				if (dist[Next].first >= sumCost && sumCost != INF)
				{
					//새로운 최단 거리라면
					if (dist[Next].first > sumCost)
					{
						//최단 거리 값 입력
						dist[Next].first = sumCost;
						//이전 노드까지의 최단 경로 저장 - 기존 것 버림
						dist[Next].second = dist[cur].second;
						//새로운 최단 경로의 자신의 번호를 부여
						for (int d = 0; d < dist[Next].second.size(); d++)
						{
							dist[Next].second[d].push_back(Next);
						}
						//pq 삽입
						pq.emplace(-dist[Next].first, Next);
					}
					//기존 최단 거리와 같다면
					else
					{
						//dist[cur].second 현재 경로를 Next에게 경로 추가
						for (int d = 0; d < dist[cur].second.size(); d++)
						{
							dist[Next].second.push_back(dist[cur].second[d]);
						}
						//현재 중복 가능성 있으며, 자신의 번호가 연속되어 들어갈 가능성 있음.... 그러나 문제없다.
						for (int d = 0; d < dist[Next].second.size(); d++)
						{
							dist[Next].second[d].push_back(Next);
						}
					}
				}
			}
		}
		//도착지로 갈 수 없는 경우라면
		if (dist[end_].first == INF)
		{
			cout << "-1\n";
			break;
		}
		else
		{
			//첫 번째 사이클 (즉, 최단 경로)
			if (minDist == -1)
			{
				minDist = dist[end_].first;
				//최단 경로 파괴 - 이부분은 map, set 자료구조로 더 효율적으로 구현 가능
				for (int i = 0; i < dist[end_].second.size(); i++)
				{
					for (int j = 0; j < dist[end_].second[i].size() - 1; j++)
					{
						int a = dist[end_].second[i][j];
						int b = dist[end_].second[i][j + 1];
						for (int z = 0; z < v[a].size(); z++)
						{
							if (v[a][z].first == b)
							{
								v[a][z].second = INF;
							}
						}
					}
				}
			}
			else
			{
				//경로 파괴 후 도착지에 갈 수 없다면
				if (dist[end_].first == INF)
				{
					cout << "-1\n";
					break;
				}
				//거의 최단 경로 값 출력
				else
				{
					cout << dist[end_].first << "\n";
					break;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		int minDist = 0;
		cin >> N >> M;
		if (N == 0 && M == 0)
		{
			break;
		}
		cin >> start_ >> end_;
		v = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>());
		for (int i = 0; i < M; i++)
		{
			int num1 = 0, num2 = 0, cost = 0;
			cin >> num1 >> num2 >> cost;
			v[num1].emplace_back(num2, cost);
		}
		dijkstra();
	}
	return 0;
}