#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int dirSize = 8;
int test_case, N;
vector<vector<bool>> board, visited;
int dy[dirSize] = { -1, -2, -1, -2, 1, 2, 1, 2 };
int dx[dirSize] = { -2, -1, 2, 1, -2, -1, 2, 1 };

bool checkRange(const int y, const int x) {
	if (y > -1 && x > -1 && y < N && x < N) {
		return true;
	}
	return false;
}

int bfs(const int sy, const int sx, const int ey, const int ex) {
	int answer = 0;
	queue<pair<int, int>> q;
	visited[sy][sx] = true;
	q.emplace(sy, sx);
	while (!q.empty())
	{
		for (int i = 0, size = q.size(); i < size; i++)
		{
			pair<int, int> front = q.front();
			q.pop();
			for (int d = 0; d < dirSize; d++)
			{
				int tempY = front.first + dy[d];
				int tempX = front.second + dx[d];
				if (tempY == ey && tempX == ex)
				{
					while (!q.empty())
					{
						q.pop();
					}
					size = 0;
					break;
				}
				if (checkRange(tempY, tempX) && !visited[tempY][tempX])
				{
					visited[tempY][tempX] = true;
					q.emplace(tempY, tempX);
				}
			}
		}
		answer++;
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> test_case;
	while (test_case--)
	{
		cin >> N;
		board.assign(N, vector<bool>(N, false));
		visited.assign(N, vector<bool>(N, false));
		int sx = 0, sy = 0, ex = 0, ey = 0;
		cin >> sy >> sx >> ey >> ex;
		if (sy == ey && sx == ex)
		{
			cout << "0\n";
		}
		else
		{
			cout << bfs(sy, sx, ey, ex) << "\n";
		}
	}
	return 0;
}