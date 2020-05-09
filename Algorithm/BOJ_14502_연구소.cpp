#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int possibleWall = 3;
int N, M, emptyCount;
vector<vector<int>> map;
vector<pair<int, int>> emptyPos;
queue<pair<int, int>> virusPos;
vector<vector<int>> wallPos;
vector<int> tempWallPos;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

bool checkWall(const int y, const int x)
{
	if (y >= 0 && y < N && x >= 0 && x < M)
	{
		return true;
	}
	return false;
}

void MakeWall(const int index)
{
	if (tempWallPos.size() == possibleWall)
	{
		wallPos.emplace_back(tempWallPos);
	}
	else
	{
		for (int i = index; i < emptyPos.size(); i++)
		{
			tempWallPos.emplace_back(i);
			MakeWall(i + 1);
			tempWallPos.pop_back();
		}
	}
}

//바이러스 퍼뜨리기
int bfs(vector<vector<int>> map)
{
	int ans = emptyCount;
	queue<pair<int, int>> q = virusPos;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tempY = y + dy[i];
			int tempX = x + dx[i];
			if (checkWall(tempY, tempX) && map[tempY][tempX] == 0)
			{
				map[tempY][tempX] = 2;
				q.emplace(tempY, tempX);
				ans--;
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				emptyPos.emplace_back(i, j);
				emptyCount++;
			}
			else if (map[i][j] == 2)
			{
				virusPos.emplace(i, j);
			}
		}
	}
	emptyCount -= possibleWall;
	//가능한 벽 공간 세우기 (빈칸 개수에서 possibleWall 만큼 인덱스(i) 조합을 구한다. )
	MakeWall(0);
	//벽을 세울 조합에서 bfs() 알고리즘을 이용해 바이러스를 퍼뜨린다.
	int ans = 0;
	for (const auto& v : wallPos)
	{
		vector<vector<int>> tempMap = map;
		for (const auto z : v)
		{
			pair<int, int> pos = emptyPos[z];
			tempMap[pos.first][pos.second] = 1;
		}
		int comp = bfs(tempMap);
		ans = (ans > comp) ? ans : comp;
	}
	cout << ans << "\n";
	return 0;
}