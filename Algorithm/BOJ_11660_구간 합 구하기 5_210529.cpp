#include <iostream>
#include <vector>

using namespace std;

int N, M, total;
vector<vector<int>> board;
vector<vector<int>> sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>(N, 0));
	sum = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			total += board[i][j];
			//j == 0 행의 가장 앞부분!
			sum[i][j] = ((j == 0) ? board[i][j] : board[i][j] + sum[i][j - 1]);
		}
	}
	for (int i = 0; i < M; i++)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2; x1--, y1--, x2--, y2--;
		//주어진 구간 위의 행 빼기
		int diff = 0;
		for (int i = 0; i < x1; i++)
		{
			diff += sum[i][N - 1];
		}
		for (int i = x1; i <= x2; i++)
		{
			//좌측 행 빼기
			diff += (y1 - 1 >= 0 ? sum[i][y1 - 1] : 0);
			//우측 행 빼기
			diff += (sum[i][N - 1] - sum[i][y2]);
		}
		//주어진 구간 아래의 행 빼기
		for (int i = x2 + 1; i < N; i++)
		{
			diff += sum[i][N - 1];
		}
		cout << total - diff << "\n";
	}
	return 0;
}