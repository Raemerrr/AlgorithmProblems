#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, M;
vector<vector<char>> v;
vector<vector<bool>> visited;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool checkRange(const int y, const int x)
{
	if (y > -1 && x > -1 && x < M && y < N)
	{
		return true;
	}
	return false;
}

void BFS()
{
	queue<pair<int, int>> q;
	int answer = 1;
	q.emplace(0, 0);
	visited[0][0] = true;
	while (!q.empty())
	{
		for (int i = 0, size = q.size(); i < size; i++)
		{
			pair<int, int> front = q.front();
			q.pop();
			if (front.first == N - 1 && front.second == M - 1)
			{
				while (!q.empty())
				{
					q.pop();
				}
				cout << answer;
				break;
			}
			for (int d = 0; d < 4; d++)
			{
				int tempY = front.first + dy[d];
				int tempX = front.second + dx[d];
				if (checkRange(tempY, tempX) && !visited[tempY][tempX] && v[tempY][tempX] == '1')
				{
					visited[tempY][tempX] = true;
					q.emplace(tempY, tempX);
				}
			}
		}
		answer++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<vector<char>>(N, vector<char>(M, ' '));
	visited = vector<vector<bool>>(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			v[i][j] = str[j];
		}
	}
	BFS();
}