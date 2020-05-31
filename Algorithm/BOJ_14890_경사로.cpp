#include <iostream>
#include <vector>
using namespace std;

int N, L, ans;
vector<vector<int>> board;
//경사로 체크 판 - (상에서 하, 좌에서 우 - 두 경우의 경사로는 다르게 체크)
vector<vector<bool>> checkBoardWH;
vector<vector<bool>> checkBoardLR;

void Proc()
{
	//상에서 하
	for (int i = 0; i < N; i++)
	{
		vector<vector<bool>> tempBoard = checkBoardWH;
		vector<pair<int, int>> hPosCheck;
		vector<pair<int, int>> wPosCheck;
		bool flag = true;
		for (int j = 1; j < N; j++)
		{
			if (board[j - 1][i] < board[j][i])
			{
				if ((board[j][i] - board[j - 1][i]) > 1)
				{
					flag = false;
					break;
				}
				if ((j - L) >= 0)
				{
					//현재 위치에 이미 경사로가 세워져있다면
					if (tempBoard[j - 1][i])
					{
						flag = false;
						break;
					}
					//경사로 위치 저장
					hPosCheck.emplace_back(j - 1, i);
					for (int t = 1; t < L; t++)
					{
						//해당 위치에 경사로가 세워져있거나 높이가 다르다면
						if ((board[j - t - 1][i] != board[j - t][i]) || tempBoard[j - t][i] || tempBoard[j - t - 1][i])
						{
							flag = false;
							break;
						}
						hPosCheck.emplace_back(j - t - 1, i);
					}
					if (!flag)
					{
						break;
					}
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		//하에서 상
		if (flag)
		{
			//경사로 설치 - (상에서 하 )
			for (const auto& t : hPosCheck)
			{
				if (!tempBoard[t.first][t.second])
				{
					tempBoard[t.first][t.second] = true;
				}
			}
			//하에서 상
			for (int j = N - 1; j > 0; j--)
			{
				if (board[j][i] < board[j - 1][i])
				{
					if ((board[j - 1][i] - board[j][i]) > 1)
					{
						flag = false;
						break;
					}
					if ((j + L) <= N)
					{
						//현재 위치에 이미 경사로가 세워져있다면
						if (tempBoard[j][i])
						{
							flag = false;
							break;
						}
						wPosCheck.emplace_back(j, i);
						for (int t = 0; t < L - 1; t++)
						{
							//해당 위치에 경사로가 세워져있거나 높이가 다르다면
							if ((board[j + t + 1][i] != board[j + t][i]) || tempBoard[j + t + 1][i] || tempBoard[j + t][i])
							{
								flag = false;
								break;
							}
							wPosCheck.emplace_back(j + t + 1, i);
						}
						if (!flag)
						{
							break;
						}
					}
					else
					{
						flag = false;
						break;
					}
				}
			}
			if (flag)
			{
				//경사로 설치 - (하에서 상 )
				for (const auto& t : wPosCheck)
				{
					if (!tempBoard[t.first][t.second])
					{
						tempBoard[t.first][t.second] = true;
					}
				}
				ans++;
				checkBoardWH = tempBoard;
			}
		}
	}

	//좌에서 우
	for (int i = 0; i < N; i++)
	{
		vector<vector<bool>> tempBoard = checkBoardLR;
		bool flag = true;
		vector<pair<int, int>> leftPosCheck;
		vector<pair<int, int>> rightPosCheck;
		for (int j = 1; j < N; j++)
		{
			if (board[i][j - 1] < board[i][j])
			{
				if ((board[i][j] - board[i][j - 1]) > 1)
				{
					flag = false;
					break;
				}
				if ((j - L) >= 0)
				{
					//현재 위치에 이미 경사로가 세워져있다면
					if (tempBoard[i][j - 1])
					{
						flag = false;
						break;
					}
					leftPosCheck.emplace_back(i, j - 1);
					for (int t = 1; t < L; t++)
					{
						//해당 위치에 경사로가 세워져있거나 높이가 다르다면
						if ((board[i][j - t - 1] != board[i][j - t]) || tempBoard[i][j - t - 1] || tempBoard[i][j - t])
						{
							flag = false;
							break;
						}
						leftPosCheck.emplace_back(i, j - t - 1);
					}
					if (!flag)
					{
						break;
					}
				}
				else
				{
					flag = false;
					break;
				}
			}

		}
		//우에서 좌
		if (flag)
		{
			//경사로 설치 - (좌에서 우 )
			for (const auto& t : leftPosCheck)
			{
				if (!tempBoard[t.first][t.second])
				{
					tempBoard[t.first][t.second] = true;
				}
			}
			//우에서 좌
			for (int j = N - 1; j > 0; j--)
			{
				if (board[i][j] < board[i][j - 1])
				{
					if ((board[i][j - 1] - board[i][j]) > 1)
					{
						flag = false;
						break;
					}
					if ((j + L) <= N)
					{
						//현재 위치에 이미 경사로가 세워져있다면
						if (tempBoard[i][j])
						{
							flag = false;
							break;
						}
						rightPosCheck.emplace_back(i, j);
						for (int t = 0; t < L - 1; t++)
						{
							//해당 위치에 경사로가 세워져있거나 높이가 다르다면
							if ((board[i][j + t + 1] != board[i][j + t]) || tempBoard[i][j + t + 1] || tempBoard[i][j + t])
							{
								flag = false;
								break;
							}
							rightPosCheck.emplace_back(i, j + t + 1);
						}
						if (!flag)
						{
							break;
						}
					}
					else
					{
						flag = false;
						break;
					}
				}
			}
			if (flag)
			{
				//경사로 설치 - (우에서 좌 )
				for (const auto& t : rightPosCheck)
				{
					if (!tempBoard[t.first][t.second])
					{
						tempBoard[t.first][t.second] = true;
					}
				}
				checkBoardLR = tempBoard;
				ans++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L;
	board = vector<vector<int>>(N, vector<int>(N, 0));
	checkBoardLR = vector<vector<bool>>(N, vector<bool>(N, false));
	checkBoardWH = vector<vector<bool>>(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	Proc();
	cout << ans << "\n";
	return 0;
}