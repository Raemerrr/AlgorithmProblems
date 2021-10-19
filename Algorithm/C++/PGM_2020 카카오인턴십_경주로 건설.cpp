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

//범위 계산 등 여러모로 쓰임...
int boardSize = 0;

//범위 체크
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
	//각 보드의 최소 값을 구할 맵
	map<pair<int, int>, int> m;
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			//최대 값이라고 생각하는 값을 미리 넣어놓는다.
			m[pair<int, int>(i, j)] = 999999999;
		}
	}

	//BFS알고리즘
	queue<Info> q;
	q.emplace(0, 0, 0, -1);
	m[pair<int, int>(0, 0)] = 0;
	while (!q.empty())
	{
		//한 사이클 - 큰 의미는 없음.
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
					//front가 시작 위치(0, 0)라면 방향에 따른 값 증가 없음.
					if (front.y == 0 && front.x == 0)
					{
						tempPrice += 100;
					}
					else
					{
						//커브 (직선(100) + 커브(500) )
						if (front.curDir != tempDir)
						{
							tempPrice += 600;
						}
						//직선
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