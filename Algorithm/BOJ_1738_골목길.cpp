#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int INF = 100000000;
int N, M;
map<pair<int, int>, int> m;
map<pair<int, int>, bool> inputCheck;
vector<pair<int, vector<int>>> dist;
set<int> cycles;

void bellmanFord()
{
	bool flag = false;
	for (int i = 1; i <= N; i++)
	{
		for (auto& d : m)
		{
			int from = d.first.first;
			int to = d.first.second;
			int cost = d.second;
			if (dist[from].first == INF)
			{
				continue;
			}
			if (dist[to].first > dist[from].first + cost)
			{
				dist[to].first = dist[from].first + cost;
				dist[to].second = dist[from].second;
				dist[to].second.push_back(to);
				//사이클을 이룬다는 증거 해당 구간을 저장해두자.
				if (i == N)
				{
					cycles.insert(to);
					cycles.insert(from);
				}
			}
		}
	}
	//현재까지 최적의 해를 저장
	pair<int, vector<int>> ans = dist[N];

	//사이클이 존재 한다면
	if (!cycles.empty())
	{
		//해당 사이클에서 N까지 도달 가능한지 확인.
		for (const auto& d : cycles)
		{
			dist = vector<pair<int, vector<int>>>(N + 1, pair<int, vector<int>>(INF, vector<int>()));
			dist[d].first = 0;
			dist[d].second = vector<int>{ d };
			for (int i = 1; i < N; i++)
			{
				for (auto& d : m)
				{
					int from = d.first.first;
					int to = d.first.second;
					int cost = d.second;
					if (dist[from].first == INF)
					{
						continue;
					}
					if (dist[to].first > dist[from].first + cost)
					{
						dist[to].first = dist[from].first + cost;
						dist[to].second = dist[from].second;
						dist[to].second.push_back(to);
					}
				}
			}
			//도달 가능하다면 -1 출력 처리
			if (dist[N].first != INF)
			{
				flag = true;
				break;
			}
		}
	}

	if (flag)
	{
		cout << "-1\n";
	}
	else
	{
		if (ans.first != INF)
		{
			for (const auto& d : ans.second)
			{
				cout << d << " ";
			}
			cout << "\n";
		}
		else
		{
			cout << "-1\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	dist = vector<pair<int, vector<int>>>(N + 1, pair<int, vector<int>>(INF, vector<int>()));
	dist[1].first = 0;
	dist[1].second = vector<int>{ 1 };
	int num1 = 0, num2 = 0, cost = 0;
	//골목길 단방향 연결
	for (int i = 0; i < M; i++)
	{
		cin >> num1 >> num2 >> cost;
		//양의 사이클을 찾아야 하므로 비용의 부호를 바꿔 기존 음의 사이클을 찾는 로직을 태운다.
		cost *= -1;
		//inputCheck 입력 확인용 기존 입력된 값이 있다면 작은 값으로 입력
		if (!inputCheck[pair<int, int>(num1, num2)])
		{
			m[pair<int, int>(num1, num2)] = cost;
			inputCheck[pair<int, int>(num1, num2)] = true;
		}
		else
		{
			int tCost = m[pair<int, int>(num1, num2)];
			m[pair<int, int>(num1, num2)] = tCost < cost ? tCost : cost;
		}
	}
	bellmanFord();
	return 0;
}