#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Fish
{
	int y;
	int x;
	//속도
	int s;
	//방향
	int d;
	//크기
	int z;
	Fish() {}
	Fish(int y, int x, int s, int d, int z) : y(y), x(x), s(s), d(d), z(z) {}
};

const int MAX = 200 + 1;
int R, C, U, ans;
vector<int> board[MAX][MAX];
map<int, Fish> m;

//방향 조건
const int _top = 1;
const int _bottom = 2;
const int _right = 3;
const int _left = 4;

bool CheckWall(const int y, const int x)
{
	if (y > 0 && x > 0 && y <= R && x <= C)
	{
		return true;
	}
	return false;
}

int Hit(const int xPos)
{
	int curPos = xPos + 1;
	int res = 0;
	for (int i = 1; i <= R; i++)
	{
		if (!board[i][curPos].empty())
		{
			res = m[board[i][curPos][0]].z;
			m.erase(board[i][curPos][0]);
			board[i][curPos].clear();
			break;
		}
	}
	return res;
}

pair<int, int> CheckDir(const int d)
{
	pair<int, int> dir(0, 0);
	if (d == _top)
	{
		dir = pair<int, int>(-1, 0);
	}
	else if (d == _bottom)
	{
		dir = pair<int, int>(1, 0);
	}
	else if (d == _left)
	{
		dir = pair<int, int>(0, -1);
	}
	else
	{
		dir = pair<int, int>(0, 1);
	}
	return dir;
}

int Uturn(const int d)
{
	int dir = 0;
	if (d == _top)
	{
		dir = _bottom;
	}
	else if (d == _bottom)
	{
		dir = _top;
	}
	else if (d == _left)
	{
		dir = _right;
	}
	else
	{
		dir = _left;
	}
	return dir;
}

void Move()
{
	vector<pair<int, pair<int, int>>> pos;
	for (auto& d : m)
	{
		int posY = d.second.y;
		int posX = d.second.x;
		board[posY][posX].pop_back();
		//Speed Loop 줄이기
		int speed = d.second.s;
		if (d.second.d == _top || d.second.d == _bottom)
		{
			speed = speed % (2 * R - 2);
		}
		else
		{
			speed = speed % (2 * C - 2);
		}
		for (int i = 0; i < speed; i++)
		{
			pair<int, int> dir = CheckDir(d.second.d);
			int tempY = posY + dir.first;
			int tempX = posX + dir.second;
			if (!CheckWall(tempY, tempX))
			{
				//방향 전환
				d.second.d = Uturn(d.second.d);
				i--;
				continue;
			}
			posY = tempY;
			posX = tempX;
		}
		d.second.y = posY;
		d.second.x = posX;
		pos.emplace_back(d.first, make_pair(posY, posX));
	}
	//물고기 전체 이동 후 이동 자리 입력
	for (const auto& d : pos)
	{
		board[d.second.first][d.second.second].emplace_back(d.first);
	}
}

void Eat()
{
	//물고기들의 위치를 탐색하며 같은 위치에 물고기가 존재하다면
	set<pair<int, int>> pos;
	for (const auto& d : m)
	{
		if (board[d.second.y][d.second.x].size() > 1)
		{
			pos.emplace(d.second.y, d.second.x);
		}
	}

	for (const auto& d : pos)
	{
		int maxSize = 0;
		int ID = 0;
		//탐색을 통해 구한 위치의 가장 큰 물고기 찾기
		for (const auto& t : board[d.first][d.second])
		{
			if (maxSize < m[t].z)
			{
				maxSize = m[t].z;
				ID = t;
			}
		}
		//m에서 지우기
		for (const auto& t : board[d.first][d.second])
		{
			if (t != ID)
			{
				m.erase(t);
			}
		}
		//보드 새로 깔기
		board[d.first][d.second].clear();
		board[d.first][d.second].emplace_back(ID);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> U;
	if (U == 0)
	{
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < U; i++)
	{
		int r1 = 0, c1 = 0, s = 0, d = 0, z = 0;
		cin >> r1 >> c1 >> s >> d >> z;
		board[r1][c1].emplace_back(i);
		m[i] = Fish(r1, c1, s, d, z);
	}
	for (int i = 0; i < C; i++)
	{
		//물고기 잡기
		ans += Hit(i);
		//상어 이동
		Move();
		//겹치는 상어 먹기
		Eat();
	}
	cout << ans;
	return 0;
}