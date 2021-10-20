#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int N, M;
//벽과 공간을 저장하는 맵 변수
vector<string> map;
//현재 지점 방문 시 가장 적은 값을 체크하는 변수
vector<vector<int>> check;
//방문가능 방향
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

//방문 가능한 지점인지 체크
bool wallCheck(const int y, const int x)
{
	if (y > -1 && y < M && x > -1 && x < N)
	{
		return true;
	}
	return false;
}

void Proc()
{
	//본인은 0,0 부터 방문하도록 설정함.
	queue<pair<pair<int, int>, int>> q;
	q.emplace(make_pair(0, 0), 0);
	while (!q.empty())
	{
		pair<int, int> pos = q.front().first;
		int cnt = q.front().second;
		q.pop();
		//현재 방문 기록이 이전 방문 기록보다 작다면
		if (check[pos.first][pos.second] <= cnt)
		{
			continue;
		}
		//현재 방문 기록이 이전 방문 기록보다 적으니 대입 
		check[pos.first][pos.second] = cnt;
		for (int i = 0; i < 4; i++)
		{
			int tempY = pos.first + dy[i];
			int tempX = pos.second + dx[i];
			//방문이 가능한 지점인지
			if (wallCheck(tempY, tempX))
			{
				int currCnt = cnt + (map[tempY][tempX] - '0');
				//현재 방문 기록과 직전(?)방문 기록이 체크 기록보다 작다면
				if (check[tempY][tempX] > currCnt)
				{
					q.emplace(make_pair(tempY, tempX), currCnt);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	check = vector<vector<int>>(M, vector<int>(N, N * M));
	map = vector<string>(M, "");
	for (int i = 0; i < M; i++)
	{
		cin >> map[i];
	}
	Proc();
	cout << check[M - 1][N - 1];
}