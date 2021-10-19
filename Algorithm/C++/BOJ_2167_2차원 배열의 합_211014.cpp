#include <iostream>
#include <vector>

using namespace std;

int N, M, K, total;
vector<vector<int>> board, horizontalSum, verticalSum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	board.assign(N, vector<int>(M, 0));
	horizontalSum.assign(N, vector<int>(M, 0));
	verticalSum.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j]; total += board[i][j];
			horizontalSum[i][j] = ((j > 0) ? horizontalSum[i][j - 1] + board[i][j] : board[i][j]);
			verticalSum[i][j] = ((i > 0) ? verticalSum[i - i][j] + board[i][j] : board[i][j]);
		}
	}
	cin >> K;
	for (int t = 0; t < K; t++)
	{
		int i = 0, j = 0, x = 0, y = 0, tempTotal = total; cin >> i >> j >> x >> y;
		// 좌측에 있는 세로열 빼기
		for (int z = 0; z < (j - 1); z++) {
			tempTotal -= verticalSum[N - 1][z];
		}
		// 우측에 있는 세로열 빼기
		for (int z = y; z < M; z++) {
			tempTotal -= verticalSum[N - 1][z];
		}
		// 상단에 있는 가로열 빼기
		for (int z = 0; z < (i - 1); z++)
		{
			tempTotal -= horizontalSum[z][M - 1 - z] - ((M - 1 - z - 1 >= 0) ? horizontalSum[z][M - 1 - z - 1] : 0);
		}
		// 하단에 있는 가로열 빼기
		for (int z = x; z < N; z++)
		{
			tempTotal -= horizontalSum[z][M - 1 - z] - ((M - 1 - z - 1 >= 0) ? horizontalSum[z][M - 1 - z - 1] : 0);
		}
		cout << tempTotal << "\n";
	}
	return 0;
}