#include <iostream>
#include <vector>

using namespace std;

struct robot
{
	//y좌표
	int y;
	//x좌표
	int x;
	//방향
	int d;
};

const int _top = 0;
const int _right = 1;
const int _bottom = 2;
const int _left = 3;
int N, M, ans;
robot r;
vector<vector<int>> board;

//이동 가능한 범위 체크
bool CheckWall(const int y, const int x)
{
	if (x >= 0 && y >= 0 && x < M && y < N)
	{
		return true;
	}
	return false;
}

//왼쪽 방향 이동 값 반환
pair<int, int> CheckDir(const int d)
{
	pair<int, int> dir(0, 0);
	if (d == _top)
	{
		dir = pair<int, int>(0, -1);
	}
	else if (d == _right)
	{
		dir = pair<int, int>(-1, 0);
	}
	else if (d == _bottom)
	{
		dir = pair<int, int>(0, 1);
	}
	else
	{
		dir = pair<int, int>(1, 0);
	}
	return dir;
}

//반대 방향 값 반환
pair<int, int> BackDir(const int d)
{
	pair<int, int> dir(0, 0);
	if (d == _top)
	{
		dir = pair<int, int>(1, 0);
	}
	else if (d == _right)
	{
		dir = pair<int, int>(0, -1);
	}
	else if (d == _bottom)
	{
		dir = pair<int, int>(-1, 0);
	}
	else
	{
		dir = pair<int, int>(0, 1);
	}
	return dir;
}

//왼쪽 방향으로 로봇 방향 입력
int SelectDir(const int d)
{
	int dir = 0;
	if (d == _top)
	{
		dir = _left;
	}
	else if (d == _left)
	{
		dir = _bottom;
	}
	else if (d == _bottom)
	{
		dir = _right;
	}
	else
	{
		dir = _top;
	}
	return dir;
}

void Proc()
{
	board[r.y][r.x] = 2;
	ans++;
	while (true)
	{
		int initDir = r.d;
		bool flag = false;
		//a,b조건 청소 시작 - 최대 4방향
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> d = CheckDir(r.d);
			int tempY = r.y + d.first;
			int tempX = r.x + d.second;
			r.d = SelectDir(r.d);
			if (CheckWall(tempY, tempX) && board[tempY][tempX] == 0)
			{
				//이동
				r.y = tempY;
				r.x = tempX;
				//청소
				board[tempY][tempX] = 2;
				ans++;
				flag = true;
				//청소 했으면 종료
				break;
			}
		}
		//c, d 조건
		if (!flag && r.d == initDir)
		{
			pair<int, int> d = BackDir(r.d);
			int tempY = r.y + d.first;
			int tempX = r.x + d.second;
			//c 상황
			if (board[tempY][tempX] != 1)
			{
				r.y = tempY;
				r.x = tempX;
			}
			//d상황
			else
			{
				break;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>(M, 0));
	cin >> r.y >> r.x >> r.d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	Proc();
	cout << ans << "\n";
	return 0;
}