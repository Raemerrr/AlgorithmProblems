#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Fish
{
public:
	int y;
	int x;
	//����� ����
	int dir;
	//����� ���� ����
	bool aliveFlag;
	Fish()
	{
		//�⺻������ ���� ó��
		dir = -1;
		aliveFlag = false;
	}
	Fish(int y, int x, int dir) :y(y), x(x), dir(dir), aliveFlag(true) {}
};

pair<int, int> direc[]{ {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
enum direction { none = -1, _up, u_left, _left, d_left, _down, d_right, _right, u_right };
int ans;

//���� �����ִ� �Լ�
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

//���� üũ
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
	//����� �̵� ��
	for (int index = 1; index <= 16; index++)
	{
		//��� �ִ� ����⸸
		if (fishs[index].aliveFlag)
		{
			//�� �ð� �������� ȸ��
			for (int i = 0; i < 8; i++)
			{
				//���� �������
				int t_dir = (fishs[index].dir + i) % 8;
				pair<int, int> tPos = getPos(static_cast<direction>(t_dir));
				int tempY = fishs[index].y + tPos.first;
				int tempX = fishs[index].x + tPos.second;
				//���� ����,���ĭ X 
				if (CheckWall(tempY, tempX) && board[tempY][tempX] != -1)
				{
					int t_index = board[tempY][tempX];
					//����� ���� �� swap
					if (t_index > 0)
					{
						//board �� ����
						board[fishs[index].y + tPos.first][fishs[index].x + tPos.second] = index;
						board[fishs[index].y][fishs[index].x] = t_index;
						//fishs �� ���� - swap
						swap(fishs[index].y, fishs[t_index].y);
						swap(fishs[index].x, fishs[t_index].x);
					}
					//�ƴϸ� �̵� �� ����
					else
					{
						//board �� ����
						board[fishs[index].y + tPos.first][fishs[index].x + tPos.second] = index;
						board[fishs[index].y][fishs[index].x] = 0;
						//fishs �� ����
						fishs[index].y += tPos.first;
						fishs[index].x += tPos.second;
					}
					//����� ���� �ٲ��ֱ�
					fishs[index].dir = t_dir;
					break;
				}
			}
		}
	}

	//��� �̵� ��
	pair<int, int> tPos = getPos(static_cast<direction>(fishs[-1].dir));
	//�ִ� �̵��Ÿ� �� ��ġ + 3
	for (int d = 1; d <= 3; d++)
	{
		int tempY = fishs[-1].y + (tPos.first * d);
		int tempX = fishs[-1].x + (tPos.second * d);
		if (CheckWall(tempY, tempX))
		{
			//�� ĭ�� �ƴ϶��
			if (board[tempY][tempX] != 0)
			{
				//���纻�� �ѱ�� ������ ���� ����� �̵� ��Ȳ���� ��� �̵��� ���� �� ���̱� ����
				map<int, Fish> t_fishs = fishs;
				vector<vector<int>> t_board = board;
				int currIndex = t_board[tempY][tempX];

				//���� ��� ��ġ ��ĭ ó��
				t_board[t_fishs[-1].y][t_fishs[-1].x] = 0;
				//���ο� ��� ���� �Է�
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
	//�ʱ� ����� ��ġ
	vector<vector<int>> v(4, vector<int>(4, 0));
	//����� ���� map
	map<int, Fish> m;
	//(0, 0) ��ġ�� ����� index ��
	int initCnt = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int index = 0, dir = 0;
			cin >> index >> dir;
			dir -= 1;
			//��� ��� ����
			if (i == 0 && j == 0)
			{
				initCnt = index;
				v[i][j] = -1;
				//��� �ε��� -1 ó��..
				m[-1] = Fish(i, j, dir);
				m[index].aliveFlag = false;
			}
			//������ ����� ��ġ
			else
			{
				//����� ��ġ Ȯ�� �迭
				v[i][j] = index;
				m[index] = Fish(i, j, dir);
			}
		}
	}
	DFS(v, m, initCnt);
	cout << ans << "\n";
	return 0;
}