#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int, int> P;
vector<P> pos;
vector<vector<int>> v;
vector<vector<int>> dp;
vector<vector<bool>> visited;
int N;
bool flag;

//각 지점 간 거리 계산
void distanceCalc()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			//v[i][j] == 0 : 거리 계산한 기록이 없다면 계산
			if (v[i][j] == 0 && i != j)
			{
				//두 점간의 거리 |y1-y2| + |x1-x2|
				int dist = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
				v[i][j] = dist;
				v[j][i] = dist;
			}
		}
	}
}

void dfs(int index)
{
	if (index == N - 1)
	{
		flag = true;
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			//!flag : 페스티벌에 도착한 적이 없다면
			//v[index][i] <= 1000 : 최대 가능 거리
			if (!flag && index != i && !visited[index][i] && v[index][i] <= 1000)
			{
				visited[index][i] = true;
				visited[i][index] = true;
				dfs(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		cin >> N;
		//초기화
		N += 2;
		pos.clear();
		v = vector<vector<int>>(N, vector<int>(N, 0));
		dp = vector<vector<int>>(N, vector<int>(N, 0));
		visited = vector<vector<bool>>(N, vector<bool>(N, false));
		flag = false;
		//좌표 저장
		for (int i = 0; i < N; i++)
		{
			int y = 0, x = 0;
			cin >> y >> x;
			pos.emplace_back(y, x);
		}
		//각 지점(?)마다 서로간의 거리를 계산
		distanceCalc();
		//상근이네 집부터 출발!
		dfs(0);

		//페스티벌에 도착 했으면
		if (flag)
		{
			cout << "happy\n";
		}
		//페스티벌에 도착하지 못했다면
		else
		{
			cout << "sad\n";
		}
	}
	return 0;
}