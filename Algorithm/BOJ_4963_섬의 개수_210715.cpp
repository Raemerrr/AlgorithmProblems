#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int DIR_SIZE = 8;
int w, h, answer;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dx[DIR_SIZE] = { 1,0,-1,0,-1,-1,1,1 };
int dy[DIR_SIZE] = { 0,-1,0,1,1,-1,1,-1 };

bool checkRange(const int y, const int x) {
	if (y > -1 && x > -1 && y < h && x < w) {
		return true;
	}
	return false;
}

void dfs(const int y, const int x) {
	for (int d = 0; d < DIR_SIZE; d++)
	{
		int tempY = y + dy[d];
		int tempX = x + dx[d];
		if (checkRange(tempY, tempX) && board[tempY][tempX] && !visited[tempY][tempX])
		{
			visited[tempY][tempX] = true;
			dfs(tempY, tempX);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		cin >> w >> h; answer = 0;
		if (w == 0 && h == 0) break;
		board.assign(h, vector<int>(w, 0));
		visited.assign(h, vector<bool>(w, false));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (board[i][j] && !visited[i][j])
				{
					visited[i][j] = true;
					dfs(i, j);
					answer++;
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}