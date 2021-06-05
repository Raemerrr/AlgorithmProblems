#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, Q, total;
vector<vector<int>> board;
vector<vector<int>> sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> Q;
	board.assign(R, vector<int>(C, 0));
	sum.assign(R, vector<int>(C, 0));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
			sum[i][j] = (j > 0) ? board[i][j] + sum[i][j - 1] : board[i][j];
			total += board[i][j];
		}
	}
	while (Q--)
	{
		int tempTotal = total;
		int r1 = 0, c1 = 0, r2 = 0, c2 = 0; cin >> r1 >> c1 >> r2 >> c2; r1--, c1--, r2--, c2--;
		//구간 상단 구역 빼기
		for (int i = 0; i < r1; i++)
		{
			tempTotal -= sum[i][C - 1];
		}

		//구간 좌, 우 구역 빼기
		for (int i = r1; i <= r2; i++)
		{
			tempTotal -= (c1 > 0) ? sum[i][c1 - 1] : 0;
			tempTotal -= (sum[i][C - 1] - sum[i][c2]);
		}

		//구간 하단 구역 빼기
		for (int i = r2 + 1; i < R; i++)
		{
			tempTotal -= sum[i][C - 1];
		}
		cout << (tempTotal / ((r2 - r1 + 1) * (c2 - c1 + 1))) << "\n";
	}
	return 0;
}