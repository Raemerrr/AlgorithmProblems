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
	//�迭 �̾� ���̱� - �迭 x�� y�� ȸ���ؼ� �̾� ���̱�
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
			//������ ��� ���� ��� - cnt�� L���� Ŭ��
			else if (board[i][j] + 1 == board[i][j + 1] && cnt >= L)
			{
				cnt = 1;
			}
			//������ ��� ���� ��� (cnt�� ������ �տ� ���� ���縦 ����)
			else if (board[i][j] - 1 == board[i][j + 1] && cnt >= 0)
			{
				cnt = (1 - L);
			}
			else
			{
				break;
			}
		}
		//������ ���� �� ���Ұ� �� �������� ������ ���ΰ� ���� ��
		if (j == N - 1 && cnt >= 0)
		{
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}