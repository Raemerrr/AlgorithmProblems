#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

enum DIR
{
	EAST = 1,
	WEST,
	SOUTH,
	NORTH
};

struct Position
{
	int y;
	int x;
	//다른 Position객체와 비교
	bool operator==(const Position& rhs) const
	{
		return y == rhs.y && x == rhs.x;
	}
};

struct Player
{
	Position pos;
	DIR d;
	//다른 Player객체와 비교
	bool operator==(const Player& rhs) const
	{
		return pos == rhs.pos && d == rhs.d;
	}
};

const int INF = 987654321;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int M, N, answer = INF;
vector<vector<int>> board;
vector<vector<int>> boardState;
Player S, E;

bool checkRange(const int y, const int x) {
	if (y > -1 && x > -1 && y < M && x < N) return true;
	return false;
}

int rotation(const DIR& curDir, const DIR& nextDir, bool isLeft) {
	int result = 0;
	if (curDir == DIR::EAST)
	{
		switch (nextDir)
		{
		case DIR::SOUTH:
			result = ((isLeft) ? 3 : 1);
			break;
		case DIR::WEST:
			result = ((isLeft) ? 2 : 2);
			break;
		case DIR::NORTH:
			result = ((isLeft) ? 1 : 3);
			break;
		}
	}
	else if (curDir == DIR::NORTH)
	{
		switch (nextDir)
		{
		case DIR::SOUTH:
			result = ((isLeft) ? 2 : 2);
			break;
		case DIR::WEST:
			result = ((isLeft) ? 1 : 3);
			break;
		case DIR::EAST:
			result = ((isLeft) ? 3 : 1);
			break;
		}
	}
	else if (curDir == DIR::WEST)
	{
		switch (nextDir)
		{
		case DIR::SOUTH:
			result = ((isLeft) ? 1 : 3);
			break;
		case DIR::NORTH:
			result = ((isLeft) ? 3 : 1);
			break;
		case DIR::EAST:
			result = ((isLeft) ? 2 : 2);
			break;
		}
	}
	else// if (curDir == DIR::SOUTH)
	{
		switch (nextDir)
		{
		case DIR::WEST:
			result = ((isLeft) ? 3 : 1);
			break;
		case DIR::NORTH:
			result = ((isLeft) ? 2 : 2);
			break;
		case DIR::EAST:
			result = ((isLeft) ? 1 : 3);
			break;
		}
	}
	return result;
}

void bfs() {
	queue<pair<Player, int>> q;
	q.push({ S , boardState[S.pos.y][S.pos.x] });
	while (!q.empty())
	{
		Player front = q.front().first;
		int frontState = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tempY = front.pos.y + dy[i];
			int tempX = front.pos.x + dx[i];
			DIR tempD = static_cast<DIR>(i + 1);
			if (checkRange(tempY, tempX) && board[tempY][tempX] == 0)// && frontState + 1 < boardState[tempY][tempX]) 
			{
				//front와 같은 방향이면 1~3칸 전진
				if (tempD == front.d)
				{
					bool flag = false;
					for (int go = 1; go <= 3; go++)
					{
						int ttempY = front.pos.y + dy[i] * go;
						int ttempX = front.pos.x + dx[i] * go;
						if (checkRange(ttempY, ttempX) && board[ttempY][ttempX] == 0)// && frontState + 1 < boardState[ttempY][ttempX]) 
						{
							tempY = ttempY;
							tempX = ttempX;
							boardState[ttempY][ttempX] = min(boardState[ttempY][ttempX], frontState + 1);
							flag = true;
							if (E.pos.y == tempY && E.pos.x == tempX)
							{
								break;
							}
						}
						else
						{
							break;
						}
					}
					if (flag)
					{
						Player pp = { {tempY,tempX}, tempD };
						// 목적지 도착
						if (pp.pos == E.pos)
						{
							answer = min(answer, boardState[pp.pos.y][pp.pos.x] + min(rotation(pp.d, E.d, true), rotation(pp.d, E.d, false)));
							boardState[E.pos.y][E.pos.x] = INF;
						}
						else
						{
							q.push({ pp, boardState[pp.pos.y][pp.pos.x] });
						}
					}
				}
				//다른 방향은 그대로 입력
				else
				{
					Player pp = { {front.pos.y, front.pos.x}, tempD };
					// 목적지 도착
					if (pp.pos == E.pos)
					{
						answer = min(answer, boardState[pp.pos.y][pp.pos.x] + min(rotation(pp.d, E.d, true), rotation(pp.d, E.d, false)));
						boardState[E.pos.y][E.pos.x] = INF;
					}
					else
					{
						int tempState = frontState + min(rotation(tempD, front.d, true), rotation(tempD, front.d, false));
						q.push({ pp, tempState });
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	board.assign(M, vector<int>(N, 0));
	boardState.assign(M, vector<int>(N, INF));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	int dirNum = 0;
	cin >> S.pos.y >> S.pos.x >> dirNum; S.d = static_cast<DIR>(dirNum); S.pos.y--, S.pos.x--;
	boardState[S.pos.y][S.pos.x] = 0;
	cin >> E.pos.y >> E.pos.x >> dirNum; E.d = static_cast<DIR>(dirNum); E.pos.y--, E.pos.x--;
	if (S.pos == E.pos)
	{
		cout << min(rotation(S.d, E.d, true), rotation(S.d, E.d, false)) << "\n";
	}
	else
	{
		bfs();
		cout << answer << "\n";
	}
	return 0;
}
