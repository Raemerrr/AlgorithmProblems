#include <iostream>
#include <vector>

using namespace std;

int N, L, ans = 0;
vector<vector<int>> board;
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L;
	board = vector<vector<int>>(N * 2, vector<int>(N, 0));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> board[y][x];
		}
	}
	//배열 이어 붙이기 - 배열 x축 y축 회전해서 이어 붙이기
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			board[N + y][x] = board[x][y];
		}
	}
	int i, j, cnt;
	for (i = 0; i < 2 * N; i++)
	{
		cnt = 1;
		for (j = 0; j < N - 1; j++)
		{
			if (board[i][j] == board[i][j + 1])
			{
				cnt++;
			}
			//오르막 경사 가능 경우 - cnt가 L보다 클때
			else if (board[i][j] + 1 == board[i][j + 1] && cnt >= L)
			{
				cnt = 1;
			}
			//내리막 경사 가능 경우 (cnt가 음수면 앞에 경사로 존재를 뜻함)
			else if (board[i][j] - 1 == board[i][j + 1] && cnt >= 0)
			{
				cnt = (1 - L);
			}
			else
			{
				break;
			}
		}
		//마지막 까지 다 돌았고 맨 마지막에 부족한 경사로가 없을 시
		if (j == N - 1 && cnt >= 0)
		{
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}