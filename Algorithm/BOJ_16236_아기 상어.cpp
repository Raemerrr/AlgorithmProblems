/*
��õ �ݷ�
#input
3
9 2 2
2 2 3
1 3 1

#output
2

#input
2
9 3
3 1

#output
0

#input
6
1 2 0 3 1 6
1 0 5 0 0 0
1 0 2 0 2 0
0 1 4 0 2 5
6 6 3 0 3 3
4 9 6 0 2 2

#output
0
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, killCnt, fishCnt, ans;
vector<vector<int>> board;
int dy[]{ 0,1,0,-1 };
int dx[]{ 1,0,-1,0 };
int babySize = 2;
pair<int, int> sharkPos;
pair<int, int> preSharkPos;

bool CheckWall(const int y, const int x)
{
	if (y >= 0 && x >= 0 && y < N && x < N)
	{
		return true;
	}
	return false;
}

//��ü ���� Ž���Ͽ� ��Ƹ��� ����� ���翩��
bool isExit()
{
	for (const auto& z : board)
	{
		for (const auto& d : z)
		{
			if (d != 0 && babySize > d)
			{
				return false;
			}
		}
	}
	return true;
}

void Move()
{
	int tempAns = 0;
	vector<vector<bool>> visited = vector<vector<bool>>(N, vector<bool>(N, false));
	vector<pair<int, int>> pos;
	queue<pair<int, int>> q;
	q.emplace(sharkPos.first, sharkPos.second);
	//�Ʊ� �� ���� �ڸ��� �ٽ� �湮�� �ʿ� ������, �����Ͽ� �̵� �����ϵ���
	visited[sharkPos.first][sharkPos.second] = true;
	board[sharkPos.first][sharkPos.second] = 0;
	while (!q.empty())
	{
		tempAns++;
		//���� q.size()��ŭ ������ ���� ���� �̵� �Ÿ��� ī��Ʈ �ϱ�����
		for (int i = 0, size = q.size(); i < size; i++)
		{
			pair<int, int> front = q.front();
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				int tempY = front.first + dy[d];
				int tempX = front.second + dx[d];
				if (CheckWall(tempY, tempX) && board[tempY][tempX] <= babySize && !visited[tempY][tempX])
				{
					q.emplace(tempY, tempX);
					visited[tempY][tempX] = true;
					//Shark�� �̵� ���� �ϸ鼭 ���� �� �ִ� ������� ��ġ���
					if (board[tempY][tempX] != 0 && board[tempY][tempX] < babySize)
					{
						pos.emplace_back(tempY, tempX);
					}
				}
			}
		}
		//���� �̵��� �Ÿ� ���� ����Ⱑ ���� �Ѵٴ� �ǹ�
		if (!pos.empty())
		{
			ans += tempAns;
			//���� ���� ������ (0, 0)�� ���������.
			sort(pos.begin(), pos.end());
			//�Ʊ� ��� ��ġ ����
			sharkPos.first = pos[0].first;
			sharkPos.second = pos[0].second;
			//��� �Ծ���
			board[sharkPos.first][sharkPos.second] = 9;
			killCnt++;
			fishCnt--;
			if (killCnt == babySize)
			{
				babySize++;
				killCnt = 0;
			}
			break;
		}
	}

}

void Proc()
{
	while (true)
	{
		//���� ��ġ ��� (���� ���� ����)
		preSharkPos = sharkPos;

		//�Ʊ� ��� �̵�
		Move();

		//���� �Ǵ� ����
		//-�Ʊ� ���� ���� ����Ⱑ ����.
		//-���� ����Ⱑ ����.
		//-���� ��ġ�� ����.
		if (isExit() || fishCnt == 0 || preSharkPos == sharkPos)
		{
			break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	board = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 9)
			{
				fishCnt++;
			}
			else if (board[i][j] == 9)
			{
				sharkPos.first = i;
				sharkPos.second = j;
			}
		}
	}
	if (fishCnt == 0)
	{
		cout << "0\n";
		return 0;
	}
	Proc();
	cout << ans << "\n";
	return 0;
}