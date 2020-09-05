#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int INF = 100000000;
int N, M, W;
//입력 여부 판단
map<pair<int, int>, bool> inputCheck;
map<pair<int, int>, int> m;
vector<int> dist;

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
			// 끊어진 곳에서 음의 사이클이 존재 할 수 있기때문에(?)
			//if (dist[from] == INF)
			//{
			//	continue;
			//}
			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				if (i == N)
				{
					flag = true;
					break;
				}
			}
		}
	}

	if (flag)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		cin >> N >> M >> W;
		dist = vector<int>(N + 1, INF);
		dist[1] = 0;
		int num1 = 0, num2 = 0, cost = 0;
		//도로 양방향 연결
		for (int i = 0; i < M; i++)
		{
			cin >> num1 >> num2 >> cost;
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
			if (!inputCheck[pair<int, int>(num2, num1)])
			{
				m[pair<int, int>(num2, num1)] = cost;
				inputCheck[pair<int, int>(num2, num1)] = true;
			}
			else
			{
				int tCost = m[pair<int, int>(num2, num1)];
				m[pair<int, int>(num2, num1)] = tCost < cost ? tCost : cost;
			}
		}
		//웜홀 단방향 연결
		for (int i = 0; i < W; i++)
		{
			cin >> num1 >> num2 >> cost;
			if (!inputCheck[pair<int, int>(num1, num2)])
			{
				m[pair<int, int>(num1, num2)] = -cost;
				inputCheck[pair<int, int>(num1, num2)] = true;
			}
			else
			{
				int tCost = m[pair<int, int>(num1, num2)];
				m[pair<int, int>(num1, num2)] = tCost < -cost ? tCost : -cost;
			}
		}
		bellmanFord();
		m.clear();
		inputCheck.clear();
	}
	return 0;
}