#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int INF = 10000000;
int N, ans;
vector<vector<char>> board;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

bool checkRange(const int y, const int x)
{
	if (y > -1 && x > -1 && y < N && x < N)
	{
		return true;
	}
	return false;
}

int dijkstra()
{
	priority_queue<pair<int, pair<int, int>> > pq;
	vector<vector<int>> dist(N, vector<int>(N, INF));
	pq.emplace(0, pair<int, int>(0, 0));
	dist[0][0] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		pair<int, int> cur = pq.top().second;

		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int tempY = cur.first + dy[i];
			int tempX = cur.second + dx[i];
			if (checkRange(tempY, tempX))
			{
				// '0' 벽일 경우에는 비용을 증가 시킨다.
				if (board[tempY][tempX] == '0' && dist[tempY][tempX] > cost + 1)
				{
					dist[tempY][tempX] = cost + 1;
					pq.emplace(-dist[tempY][tempX], pair<int, int>(tempY, tempX));
				}
				//벽이 아닐 경우에는 비용을 증가 시키지 않는다.
				if (board[tempY][tempX] == '1' && dist[tempY][tempX] > cost)
				{
					dist[tempY][tempX] = cost;
					pq.emplace(-dist[tempY][tempX], pair<int, int>(tempY, tempX));
				}
			}
		}
	}
	return dist[N - 1][N - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	board = vector<vector<char>>(N, vector<char>(N, 0));
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			board[i][j] = str[j];
		}
	}
	int cost = dijkstra();
	cout << cost << "\n";
	return 0;
}