#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int R, C;
vector<vector<char>> board;
vector<vector<bool>> visited;
pair<int, int> answer;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool checkRange(const int y, const int x) {
	if (x > -1 && y > -1 && y < R && x < C) {
		return true;
	}
	return false;
}

pair<int, int> checkValue(const int y, const int x) {
	pair<int, int> result;
	if (board[y][x] == 'k')
	{
		result.first += 1;
	}
	else if (board[y][x] == 'v')
	{
		result.second += 1;
	}
	return result;
}

pair<int, int> bfs(const int y, const int x) {
	pair<int, int> result;
	queue<pair<int, int>> q;
	q.emplace(y, x);
	visited[y][x] = true;
	if (board[y][x] == 'k')
	{
		result.first += 1;
	}
	else if (board[y][x] == 'v')
	{
		result.second += 1;
	}

	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int tempY = front.first + dy[d];
			int tempX = front.second + dx[d];
			if (checkRange(tempY, tempX) && !visited[tempY][tempX] && board[tempY][tempX] != '#')
			{
				visited[tempY][tempX] = true;
				q.emplace(tempY, tempX);
				if (board[tempY][tempX] == 'k')
				{
					result.first += 1;
				}
				else if (board[tempY][tempX] == 'v')
				{
					result.second += 1;
				}
			}
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	board.assign(R, vector<char>(C, ' '));
	visited.assign(R, vector<bool>(C, false));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			pair<int, int> result;
			if (!visited[i][j] && board[i][j] != '#')
			{
				result = bfs(i, j);
				if (result.second < result.first)
				{
					answer.first += result.first;
				}
				else
				{
					answer.second += result.second;
				}
			}
		}
	}
	cout << answer.first << " " << answer.second << "\n";
	return 0;
}