#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
const int INF = 100000000;
int N, M, S, D;
map<int, map<int, int>> nodes;
vector<pair<int, set<vector<int>>>> m;

int Solution()
{
	int answer = 0;
	//첫번째 최단 경로 찾기
	priority_queue<pair<int, int>> pq;
	m[S].first = 0;
	pq.emplace(m[S].first, S);
	m[S].second.insert(vector<int>{S});
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (const auto& d : nodes[cur])
		{
			int Next = d.first;
			int nCost = d.second;
			if (m[Next].first >= cost + nCost)
			{
				//bool flag = m[Next].first > cost + nCost ? true : false;
				if (m[Next].first == cost + nCost)
				{
					for (auto z : m[cur].second)
					{
						z.push_back(Next);
						m[Next].second.insert(z);
					}
				}
				//더 작은 경우
				else
				{
					m[Next].second.clear();
					for (auto z : m[cur].second)
					{
						z.push_back(Next);
						m[Next].second.insert(z);
					}
				}
				if (m[Next].first > cost + nCost)
				{
					m[Next].first = cost + nCost;
					pq.emplace(-m[Next].first, Next);
				}
			}
		}
	}
	//경로 끊기
	if (!m[D].second.empty())
	{
		for (const auto& d : m[D].second)
		{
			for (int i = 0; i < d.size() - 1; i++)
			{
				nodes[d[i]].erase(d[i + 1]);
			}
		}
		//다시 탐색
		m = vector<pair<int, set<vector<int>>>>(N, pair<int, set<vector<int>>>(INF, set<vector<int>>()));
		m[S].first = 0;
		pq.emplace(m[S].first, S);
		//m[S].second.insert(vector<int>{S});
		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			for (const auto& d : nodes[cur])
			{
				int Next = d.first;
				int nCost = d.second;
				if (m[Next].first > cost + nCost)
				{
					//m[Next].second.clear();
					//for (auto z : m[cur].second)
					//{
					//	z.push_back(Next);
					//	m[Next].second.insert(z);
					//}
					m[Next].first = cost + nCost;
					pq.emplace(-m[Next].first, Next);
				}
			}
		}
	}

	//if (m[D].second.empty())
	if (m[D].first >= INF)
	{
		answer = -1;
	}
	else
	{
		answer = m[D].first;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		cin >> N >> M;
		nodes.clear();
		m = vector<pair<int, set<vector<int>>>>(N, pair<int, set<vector<int>>>(INF, set<vector<int>>()));
		if (N == 0 && M == 0)
		{
			break;
		}
		cin >> S >> D;
		for (int i = 0; i < M; i++)
		{
			int num1 = 0, num2 = 0, cost = 0;
			cin >> num1 >> num2 >> cost;
			nodes[num1][num2] = cost;
		}
		cout << Solution() << "\n";
	}
	return 0;
}