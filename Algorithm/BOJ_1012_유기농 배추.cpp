#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 50;
int N, M, K, T;
vector<vector<bool>> visited;
vector<vector<bool>> map;
vector<int> ans;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,-1,0,1 };

//범위 체크 부분 - y,x >= 0 주의!
bool wallCheck(const int y, const int x)
{
	if (y < M && y >= 0 && x < N && x >= 0)
	{
		return true;
	}
	return false;
}

void Proc(const int y, const int x)
{
	queue<pair<int, int>> q;
	q.emplace(y, x);
	while (!q.empty())
	{
		int currY = q.front().first;
		int currX = q.front().second;
		q.pop();
		visited[currY][currX] = true;
		for (int i = 0; i < 4; i++)
		{
			int tempY = currY + dy[i];
			int tempX = currX + dx[i];
			if (wallCheck(tempY, tempX) && !visited[tempY][tempX] && map[tempY][tempX])
			{
				visited[tempY][tempX] = true;
				q.emplace(tempY, tempX);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		cin >> M >> N >> K;
		//초기화 부분
		map = vector<vector<bool>>(M, vector<bool>(N, false));
		visited = vector<vector<bool>>(M, vector<bool>(N, false));
		//입력 부분
		for (int i = 0; i < K; i++)
		{
			int y = 0;
			int x = 0;
			cin >> y >> x;
			map[y][x] = true;
		}

		//탐색 시작 부분
		int cnt = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] && !visited[i][j])
				{
					Proc(i, j);
					cnt++;
				}
			}
		}
		ans.emplace_back(cnt);
	}
	for (const auto& d : ans) { cout << d << "\n"; }
	return 0;
}