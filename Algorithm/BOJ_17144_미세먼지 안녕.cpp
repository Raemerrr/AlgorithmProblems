#include <iostream>
#include <vector>
#include <set>

using namespace std;
int R, C, T, ans = 2;
vector<vector<int>> board;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
vector<pair<int, int>> cleaner;
bool CheckWall(const int y, const int x)
{
	if (y >= 0 && x >= 0 && y < R && x < C)
	{
		return true;
	}
	return false;
}

void Move()
{
	//좌상단에서 청정기로
	for (int i = cleaner[0].first - 1; i > 0; i--)
	{
		board[i][0] = board[i - 1][0];
	}

	//좌하단에서 청정기로
	for (int i = cleaner[1].first + 1; i < R - 1; i++)
	{
		board[i][0] = board[i + 1][0];
	}

	//우상단에서 좌상단으로
	for (int i = 0; i < C - 1; i++)
	{
		board[0][i] = board[0][i + 1];
	}

	//우하단에서 좌하단으로
	for (int i = 0; i < C - 1; i++)
	{
		board[R - 1][i] = board[R - 1][i + 1];
	}

	//우중단(청정기 높이)에서 우상단으로
	for (int i = 0; i < cleaner[0].first; i++)
	{
		board[i][C - 1] = board[i + 1][C - 1];
	}

	//우중단(청정기 높이)에서 우하단으로
	for (int i = R - 1; i > cleaner[1].first; i--)
	{
		board[i][C - 1] = board[i - 1][C - 1];
	}

	//좌중단(청정기 높이)에서 우중단(청정기 높이)으로
	for (int i = C - 1; i > 1; i--)
	{
		board[cleaner[0].first][i] = board[cleaner[0].first][i - 1];
	}

	//좌중단(청정기 높이)에서 우중단(청정기 높이)으로
	for (int i = C - 1; i > 1; i--)
	{
		board[cleaner[1].first][i] = board[cleaner[1].first][i - 1];
	}
	//청정기 바로 앞은 미세먼지 0
	board[cleaner[0].first][1] = 0;
	board[cleaner[1].first][1] = 0;
}

//미세먼지 확산
void Bfs()
{
	for (int test_case = 0; test_case < T; test_case++)
	{
		//매번 임시맵 그려주기
		vector<vector<int>> tempBoard = vector<vector<int>>(R, vector<int>(C, 0));
		for (const auto& z : cleaner)
		{
			tempBoard[z.first][z.second] = -1;
		}
		for (int y = 0; y < R; y++)
		{
			for (int x = 0; x < C; x++)
			{
				//미세먼지 찾기
				if (board[y][x] > 0)
				{
					int cnt = 0;
					//나눠줄 여유가 되는 먼지들
					if (board[y][x] >= 5)
					{
						for (int d = 0; d < 4; d++)
						{
							int tempY = y + dy[d];
							int tempX = x + dx[d];
							if (CheckWall(tempY, tempX) && tempBoard[tempY][tempX] != -1)
							{
								tempBoard[tempY][tempX] += board[y][x] / 5;
								cnt++;
							}
						}
					}
					tempBoard[y][x] += board[y][x] - ((board[y][x] / 5) * cnt);
				}
			}
		}
		board = tempBoard;
		//먼지 이동
		Move();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> T;
	board = vector<vector<int>>(R, vector<int>(C, 0));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == -1)
			{
				cleaner.emplace_back(i, j);
			}
		}
	}
	//청정기 가동
	Bfs();
	//정답 도출
	for (const auto d : board)
	{
		for (const auto z : d)
		{
			ans += z;
		}
	}
	cout << ans << "\n";
	return 0;
}