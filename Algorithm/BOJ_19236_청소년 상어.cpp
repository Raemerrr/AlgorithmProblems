#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Fish
{
public:
	int y;
	int x;
	//물고기 방향
	int dir;
	//물고기 생존 여부
	bool aliveFlag;
	Fish()
	{
		//기본적으로 죽음 처리
		dir = -1;
		aliveFlag = false;
	}
	Fish(int y, int x, int dir) :y(y), x(x), dir(dir), aliveFlag(true) {}
};

pair<int, int> direc[]{ {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
enum direction { none = -1, _up, u_left, _left, d_left, _down, d_right, _right, u_right };
int ans;

//방향 던져주는 함수
pair<int, int> getPos(const direction d)
{
	if (d == _up)
	{
		return pair<int, int>(-1, 0);
	}
	else if (d == _down)
	{
		return pair<int, int>(1, 0);
	}
	else if (d == _left)
	{
		return pair<int, int>(0, -1);
	}
	else if (d == _right)
	{
		return pair<int, int>(0, 1);
	}
	else if (d == u_left)
	{
		return pair<int, int>(-1, -1);
	}
	else if (d == u_right)
	{
		return pair<int, int>(-1, 1);
	}
	else if (d == d_left)
	{
		return pair<int, int>(1, -1);
	}
	else// if (d == d_right)
	{
		return pair<int, int>(1, 1);
	}
}

//범위 체크
bool CheckWall(const int y, const int x)
{
	if (x >= 0 && y >= 0 && x < 4 && y < 4)
	{
		return true;
	}
	return false;
}

void DFS(vector<vector<int>> board, map<int, Fish> fishs, int cnt)
{
	ans = ans > cnt ? ans : cnt;
	//물고기 이동 부
	for (int index = 1; index <= 16; index++)
	{
		//살아 있는 물고기만
		if (fishs[index].aliveFlag)
		{
			//반 시계 방향으로 회전
			for (int i = 0; i < 8; i++)
			{
				//현재 방향부터
				int t_dir = (fishs[index].dir + i) % 8;
				pair<int, int> tPos = getPos(static_cast<direction>(t_dir));
				int tempY = fishs[index].y + tPos.first;
				int tempX = fishs[index].x + tPos.second;
				//가용 범위,상어칸 X 
				if (CheckWall(tempY, tempX) && board[tempY][tempX] != -1)
				{
					int t_index = board[tempY][tempX];
					//물고기 존재 시 swap
					if (t_index > 0)
					{
						//board 값 변경
						board[fishs[index].y + tPos.first][fishs[index].x + tPos.second] = index;
						board[fishs[index].y][fishs[index].x] = t_index;
						//fishs 값 변경 - swap
						swap(fishs[index].y, fishs[t_index].y);
						swap(fishs[index].x, fishs[t_index].x);
					}
					//아니면 이동 후 종료
					else
					{
						//board 값 변경
						board[fishs[index].y + tPos.first][fishs[index].x + tPos.second] = index;
						board[fishs[index].y][fishs[index].x] = 0;
						//fishs 값 변경
						fishs[index].y += tPos.first;
						fishs[index].x += tPos.second;
					}
					//물고기 방향 바꿔주기
					fishs[index].dir = t_dir;
					break;
				}
			}
		}
	}

	//상어 이동 부
	pair<int, int> tPos = getPos(static_cast<direction>(fishs[-1].dir));
	//최대 이동거리 현 위치 + 3
	for (int d = 1; d <= 3; d++)
	{
		int tempY = fishs[-1].y + (tPos.first * d);
		int tempX = fishs[-1].x + (tPos.second * d);
		if (CheckWall(tempY, tempX))
		{
			//빈 칸이 아니라면
			if (board[tempY][tempX] != 0)
			{
				//복사본을 넘기는 이유는 현재 물고기 이동 상황에서 상어 이동이 지속 될 것이기 때문
				map<int, Fish> t_fishs = fishs;
				vector<vector<int>> t_board = board;
				int currIndex = t_board[tempY][tempX];

				//현재 상어 위치 빈칸 처리
				t_board[t_fishs[-1].y][t_fishs[-1].x] = 0;
				//새로운 상어 정보 입력
				t_fishs[-1].y = tempY;
				t_fishs[-1].x = tempX;
				t_fishs[-1].dir = t_fishs[currIndex].dir;
				t_fishs[currIndex].aliveFlag = false;
				t_board[tempY][tempX] = -1;
				DFS(t_board, t_fishs, cnt + currIndex);
			}
		}
		else
		{
			break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//초기 물고기 위치
	vector<vector<int>> v(4, vector<int>(4, 0));
	//물고기 관리 map
	map<int, Fish> m;
	//(0, 0) 위치의 물고기 index 값
	int initCnt = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int index = 0, dir = 0;
			cin >> index >> dir;
			dir -= 1;
			//상어 출발 지점
			if (i == 0 && j == 0)
			{
				initCnt = index;
				v[i][j] = -1;
				//상어 인덱스 -1 처리..
				m[-1] = Fish(i, j, dir);
				m[index].aliveFlag = false;
			}
			//나머지 물고기 위치
			else
			{
				//물고기 위치 확인 배열
				v[i][j] = index;
				m[index] = Fish(i, j, dir);
			}
		}
	}
	DFS(v, m, initCnt);
	cout << ans << "\n";
	return 0;
}