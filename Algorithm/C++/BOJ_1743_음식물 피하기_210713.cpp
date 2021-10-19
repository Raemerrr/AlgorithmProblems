#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, answer;
vector<vector<bool>> board, visited;
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,-1,0,1 };

bool checkRange(const int y, const int x) {
	if (y > -1 && x > -1 && y < N && x < M) {
		return true;
	}
	return false;
}

int bfs(const int y, const int x) {
	int cnt = 1;
	visited[y][x] = true;
	queue<pair<int, int>> q;
	q.emplace(y, x);
	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int tempY = front.first + dy[d];
			int tempX = front.second + dx[d];
			if (checkRange(tempY, tempX) && board[tempY][tempX] && !visited[tempY][tempX])
			{
				visited[tempY][tempX] = true;
				q.emplace(tempY, tempX);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	board.assign(N, vector<bool>(M, false));
	visited.assign(N, vector<bool>(M, false));
	for (int i = 0; i < K; i++)
	{
		int num1 = 0, num2 = 0; cin >> num1 >> num2; num1--, num2--;
		board[num1][num2] = true;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] && !visited[i][j])
			{
				answer = max(answer, bfs(i, j));
			}
		}
	}
	cout << answer << "\n";
	return 0;
}