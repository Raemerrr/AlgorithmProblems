#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Texi
{
	int y;
	int x;
	Texi() { y = -1; x = -1; }
	Texi(const int y, const int x) :y(y), x(x) {}
};

struct Passenger
{
	int y;
	int x;
	bool isArrive;
	Passenger() { y = -1; x = -1; isArrive = false; }
	Passenger(const int y, const int x) :y(y), x(x), isArrive(false) {}
};

//F - 연료
int N, M, F;
vector<vector<int>> board;
Texi T;
//start
map<int, Passenger> s;
//end
map<int, Passenger> e;
//방향
int dy[] = { 0,0,1,0,-1 };
int dx[] = { 0,1,0,-1,0 };
vector<vector<bool>> visited;

bool CheckWall(const int y, const int x)
{
	if (y > 0 && x > 0 && y <= N && x <= N)
	{
		return true;
	}
	return false;
}

bool Moving(const Texi t_T, const int index)
{
	queue<Texi> q;
	q.emplace(t_T);
	visited[t_T.y][t_T.x] = true;
	int dist = 0;
	while (true)
	{
		for (int i = 0, size = q.size(); i < size; i++)
		{
			Texi front = q.front();
			q.pop();
			//이동 중 연료가 부족하다면..
			if (F < 1)
			{
				cout << "-1\n";
				return false;
			}
			//주의 승객 탑승 후엔 자신의 자리를 탐색하지 않음 1 ~ 4
			for (int d = 1; d < 5; d++)
			{
				int tempY = front.y + dy[d];
				int tempX = front.x + dx[d];
				if (CheckWall(tempY, tempX) && !visited[tempY][tempX]
					&& board[tempY][tempX] != -1)
				{
					visited[tempY][tempX] = true;
					//해당 승객 도착지라면
					if (e[index].y == tempY && e[index].x == tempX)
					{
						//return 시 연료 소모를 안하기 때문에 소모
						F--;
						dist++;
						//승객 목적지까진 연료가 0으로 도착해도 가능하기 때문
						if (F < 0)
						{
							cout << "-1\n";
							return false;
						}
						F += (dist * 2);
						return true;
					}
					q.emplace(Texi(tempY, tempX));
				}
			}
		}
		F--;
		dist++;
		//택시가 손님을 태웠으나 도착 지점이 벽으로 막혀있다면...
		if (q.empty() && !s[index].isArrive)
		{
			cout << "-1\n";
			return false;
		}
	}
}

void Proc()
{
	queue<Texi> q;
	q.emplace(T);
	//종료 조건 찾기
	while (!q.empty() && F > 0 && M > 0)
	{
		//승객 우선순위를 가리기 위해.
		vector<pair<int, int>> v;
		//다른 승객의 도착지점에서 출발하는 경우라면
		bool flag = false;
		for (int i = 0, size = q.size(); i < size; i++)
		{
			Texi front = q.front();
			q.pop();
			//승객에게 가는 중 연료가 바닥 난 상황
			if (F < 1)
			{
				cout << "-1\n";
				return;
			}
			for (int d = 0; d < 5; d++)
			{
				int tempY = front.y + dy[d];
				int tempX = front.x + dx[d];
				if (CheckWall(tempY, tempX) && !visited[tempY][tempX]
					&& board[tempY][tempX] != -1)
				{
					visited[tempY][tempX] = true;
					int index = board[tempY][tempX];
					//아직 도착하지 않은 승객 자리라면 
					if (index > 0 && !s[index].isArrive && s[index].y == tempY && s[index].x == tempX)
					{
						v.emplace_back(tempY, tempX);
						//현재 위치에 대한 처리를 위해...
						if (d == 0)
						{
							flag = true;
							break;
						}
					}
					q.emplace(Texi(tempY, tempX));
				}
			}
			//현재 위치에 대한 처리를 위해...
			if (flag)
			{
				break;
			}
		}
		//택시 연료 소모 - 현재 위치는 연료 소모를 하지 않음...
		if (!flag)
		{
			F--;
		}
		//승객이 있다면
		if (!v.empty())
		{
			//재사용을 위해 false 처리
			visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
			//주어진 우선순위를 기준으로 정렬
			sort(v.begin(), v.end());
			//q를 비우고 현재 승객 목적지부터 출발하기 위해
			while (!q.empty())
			{
				q.pop();
			}
			int index = board[v[0].first][v[0].second];
			int tempY = e[index].y;
			int tempX = e[index].x;
			//택시 이동 함수
			if (!Moving(Texi(v[0].first, v[0].second), index)) { return; };
			//도착 설정
			s[index].isArrive = true;
			//다음 출발 위치 선정
			q.emplace(Texi(tempY, tempX));
			//재사용을 위해 false 처리
			visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
			//대기 승객 수 줄이기
			M--;
		}
		//q는 비었는데 손님이 남아있다면 - 벽으로 인해 넘어가지 못하는 상황
		if (q.empty() && M > 0)
		{
			cout << "-1\n";
			return;
		}
	}
	cout << F << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> F;
	board = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int num = 0;
			cin >> num;
			// ** 벽을 -1 처리
			board[i][j] = num * -1;
		}
	}

	cin >> T.y >> T.x;
	for (int i = 1; i <= M; i++)
	{
		int sY = 0, sX = 0, eY = 0, eX = 0;
		cin >> sY >> sX >> eY >> eX;
		board[sY][sX] = i;
		s[i] = Passenger(sY, sX);
		e[i] = Passenger(eY, eX);
	}
	Proc();
	return 0;
}