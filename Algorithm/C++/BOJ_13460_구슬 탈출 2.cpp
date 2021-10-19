#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>
using namespace std;
const int MAX = 10 + 1;

struct Point
{
	int y;
	int x;
	Point()
	{
		this->y = 0;
		this->x = 0;
	}
};

struct Player
{
	Point pos;
	Point direction;
};


int N, M;
char maps[MAX][MAX];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
queue<pair<pair<Player, Player>, int>> q;

//������ Visit üũ�� ����. 
//ex) R (1,2) - B (2,3), B (5,3)... B ��ġ�� �ߺ����� �ʴ´ٸ� ����.    
//ex) R (1,2) - B (2,3), B (5,3)...B (5,3).. B ��ġ�� �ߺ��Ǳ� ������ �Ұ���.    
map<pair<int, int>, set<pair<int, int>>> m;

bool wallCheck(int y, int x)
{
	if (x > -1 && y > -1 && y < N && x < M)
	{
		return true;
	}
	return false;
}

bool dirCheck(int preY, int preX, int curY, int curX)
{
	if (preY != (curY * -1) || preX != (curX * -1))
	{
		return true;
	}
	return false;
}

//���� ���⿡ � �÷��̾ �տ� �ִ��� �Ǵ�.
bool lineCheck(Player red, Player blue, int dirY, int dirX)
{
	while (wallCheck(red.pos.y, red.pos.x))
	{
		//���� üũ �� ���̳� ���� ������ ���ִٸ� ���� ���� �ƴ�.
		if (maps[red.pos.y][red.pos.x] == '#' || maps[red.pos.y][red.pos.x] == 'O')
		{
			break;
		}
		if (blue.pos.y == red.pos.y && blue.pos.x == red.pos.x)
		{
			return true;
		}
		red.pos.y += dirY;
		red.pos.x += dirX;
	}
	return false;
}

int bfs()
{
	while (!q.empty())
	{
		pair<Player, Player> front = q.front().first;
		int Node = q.front().second;
		if (Node > 9)
		{
			return -1;
		}
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			bool redGoalFlag = false;
			bool blueGoalFlag = false;
			pair<Player, Player> tmpFront = front;
			int tmpY = tmpFront.first.pos.y + dy[dir];
			int tmpX = tmpFront.first.pos.x + dx[dir];
			if (wallCheck(tmpY, tmpX) && dirCheck(tmpFront.first.direction.y, tmpFront.first.direction.x, dy[dir], dx[dir]))
			{
				tmpFront.first.direction.y = dy[dir];
				tmpFront.first.direction.x = dx[dir];
				tmpFront.second.direction.y = dy[dir];
				tmpFront.second.direction.x = dx[dir];
				//���� �� ���⿡ B�� �����Ѵٸ� B ���� �����̰�
				if (lineCheck(tmpFront.first, tmpFront.second, dy[dir], dx[dir]))
				{
					//B ��������
					while (true)
					{
						if (maps[tmpFront.second.pos.y + dy[dir]][tmpFront.second.pos.x + dx[dir]] == '#')
						{
							break;
						}
						else if (maps[tmpFront.second.pos.y + dy[dir]][tmpFront.second.pos.x + dx[dir]] == 'O')
						{
							blueGoalFlag = true;
						}
						tmpFront.second.pos.y += dy[dir];
						tmpFront.second.pos.x += dx[dir];
					}
					//R ��������
					while (true)
					{
						if (maps[tmpFront.first.pos.y + dy[dir]][tmpFront.first.pos.x + dx[dir]] == '#' || (tmpFront.first.pos.y + dy[dir] == tmpFront.second.pos.y && tmpFront.first.pos.x + dx[dir] == tmpFront.second.pos.x))
						{
							break;
						}
						tmpFront.first.pos.y += dy[dir];
						tmpFront.first.pos.x += dx[dir];
					}

					if (!blueGoalFlag)
					{
						int currSize = m[make_pair(tmpFront.first.pos.y, tmpFront.first.pos.x)].size();
						m[make_pair(tmpFront.first.pos.y, tmpFront.first.pos.x)].emplace(tmpFront.second.pos.y, tmpFront.second.pos.x);
						if (m[make_pair(tmpFront.first.pos.y, tmpFront.first.pos.x)].size() > currSize)
						{
							q.emplace(tmpFront, Node + 1);
						}
					}
				}
				//���� �� ���⿡ B�� ���ٸ� R ���� ��������
				else
				{
					//R ��������
					while (true)
					{
						if (maps[tmpFront.first.pos.y + dy[dir]][tmpFront.first.pos.x + dx[dir]] == 'O')
						{
							redGoalFlag = true;
						}
						else if (maps[tmpFront.first.pos.y + dy[dir]][tmpFront.first.pos.x + dx[dir]] == '#')
						{
							break;
						}
						tmpFront.first.pos.y += dy[dir];
						tmpFront.first.pos.x += dx[dir];
					}
					//B ��������
					while (true)
					{
						if (maps[tmpFront.second.pos.y + dy[dir]][tmpFront.second.pos.x + dx[dir]] == 'O')
						{
							blueGoalFlag = true;
						}
						if (maps[tmpFront.second.pos.y + dy[dir]][tmpFront.second.pos.x + dx[dir]] == '#' || (tmpFront.second.pos.y + dy[dir] == tmpFront.first.pos.y && tmpFront.second.pos.x + dx[dir] == tmpFront.first.pos.x))
						{
							break;
						}
						tmpFront.second.pos.y += dy[dir];
						tmpFront.second.pos.x += dx[dir];
					}
					//R�� �����ϰ� B�� �������� �ʾҴٸ�
					if (redGoalFlag && (!blueGoalFlag))
					{
						return Node + 1;
					}
					//Visit üũ
					if (!blueGoalFlag)
					{
						int currSize = m[make_pair(tmpFront.first.pos.y, tmpFront.first.pos.x)].size();
						m[make_pair(tmpFront.first.pos.y, tmpFront.first.pos.x)].emplace(tmpFront.second.pos.y, tmpFront.second.pos.x);
						if (m[make_pair(tmpFront.first.pos.y, tmpFront.first.pos.x)].size() > currSize)
						{
							q.emplace(tmpFront, Node + 1);
						}
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	Player red;
	Player blue;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 'R')
			{
				red.pos.y = i;
				red.pos.x = j;
				red.direction.y = 99;
				red.direction.x = 99;
			}
			else if (maps[i][j] == 'B')
			{
				blue.pos.x = j;
				blue.pos.y = i;
				blue.direction.y = 99;
				blue.direction.x = 99;
			}
		}
	}
	q.emplace(make_pair(red, blue), 0);
	std::cout << bfs() << "\n";
	return 0;
}