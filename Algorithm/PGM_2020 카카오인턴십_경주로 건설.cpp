#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

struct Info
{
	int y;
	int x;
	int price;
	int curDir;
	Info() {}
	Info(const int y, const int x, const int price, const int curDir) : y(y), x(x), price(price), curDir(curDir) {}
};

//���� ��� �� ������� ����...
int boardSize = 0;

//���� üũ
bool checkRange(const int y, const int x)
{
	if (x >= 0 && y >= 0 && x < boardSize && y < boardSize)
	{
		return true;
	}
	return false;
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	boardSize = board.size();
	//�� ������ �ּ� ���� ���� ��
	map<pair<int, int>, int> m;
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			//�ִ� ���̶�� �����ϴ� ���� �̸� �־���´�.
			m[pair<int, int>(i, j)] = 999999999;
		}
	}

	//BFS�˰���
	queue<Info> q;
	q.emplace(0, 0, 0, -1);
	m[pair<int, int>(0, 0)] = 0;
	while (!q.empty())
	{
		//�� ����Ŭ - ū �ǹ̴� ����.
		for (int i = 0, size = q.size(); i < size; i++)
		{
			Info front = q.front();
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				int tempY = front.y + dy[d];
				int tempX = front.x + dx[d];
				int tempPrice = front.price;
				int tempDir = d;
				if (checkRange(tempY, tempX) && board[tempY][tempX] == 0)
				{
					//front�� ���� ��ġ(0, 0)��� ���⿡ ���� �� ���� ����.
					if (front.y == 0 && front.x == 0)
					{
						tempPrice += 100;
					}
					else
					{
						//Ŀ�� (����(100) + Ŀ��(500) )
						if (front.curDir != tempDir)
						{
							tempPrice += 600;
						}
						//����
						else
						{
							tempPrice += 100;
						}
					}
					if (m[pair<int, int>(tempY, tempX)] >= tempPrice)
					{
						m[pair<int, int>(tempY, tempX)] = tempPrice;
						q.emplace(tempY, tempX, tempPrice, tempDir);
					}
				}
			}
		}
	}
	answer = m[pair<int, int>(boardSize - 1, boardSize - 1)];
	return answer;
}

//[[0, 0, 0], [0, 0, 0], [0, 0, 0]]	900
//[[0, 0, 0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0], [0, 0, 0, 1, 0, 0, 0, 1], [0, 0, 1, 0, 0, 0, 1, 0], [0, 1, 0, 0, 0, 1, 0, 0], [1, 0, 0, 0, 0, 0, 0, 0]]	3800
//[[0, 0, 1, 0], [0, 0, 0, 0], [0, 1, 0, 1], [1, 0, 0, 0]]	2100
//[[0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 0], [0, 0, 1, 0, 0, 0], [1, 0, 0, 1, 0, 1], [0, 1, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0]]	3200


int main()
{
	//vector<vector<int>> v{ {0, 0, 0},{0, 0, 0},{0, 0, 0} };
	/*vector<vector<int>> v{ {0, 0, 0, 0, 0, 0, 0, 1},{0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 1, 0, 0},{0, 0, 0, 0, 1, 0, 0, 0},{0, 0, 0, 1, 0, 0, 0, 1},{0, 0, 1, 0, 0, 0, 1, 0},{0, 1, 0, 0, 0, 1, 0, 0},{1, 0, 0, 0, 0, 0, 0, 0} };*/
	vector<vector<int>> v{ {0, 0, 1, 0},{0, 0, 0, 0},{0, 1, 0, 1},{1, 0, 0, 0} };
	cout << solution(v) << "\n";
}