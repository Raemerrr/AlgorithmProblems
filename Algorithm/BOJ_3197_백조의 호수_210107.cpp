#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int R, C, answer;
vector<string> board;
vector<int> parent;
vector<vector<int>> idx;
queue<pair<int, int>> mergeQ;
queue<pair<int, int>> meltQ;
vector<pair<int, int>> LPos;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

int findParent(const int key) {
	if (parent[key] == key)
	{
		return key;
	}
	return parent[key] = findParent(parent[key]);
}

void merge(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b)
	{
		return;
	}
	parent[b] = a;
}

bool checkRange(const int y, const int x) {
	if (y > -1 && y < R && x > -1 && x < C)
	{
		return true;
	}
	return false;
}

void bfs_merge() {
	//연결된 물끼리 같은 구역으로 만들기
	while (!mergeQ.empty()) {
		pair<int, int> front = mergeQ.front();
		mergeQ.pop();
		meltQ.push(front);
		for (int d = 0; d < 4; d++)
		{
			int tempY = front.first + dy[d];
			int tempX = front.second + dx[d];
			if (checkRange(tempY, tempX) &&
				idx[tempY][tempX] > 0 &&
				idx[front.first][front.second] !=
				idx[tempY][tempX]
				)
			{
				merge(idx[front.first][front.second], idx[tempY][tempX]);
			}
		}
	}
}

void bfs_melt() {
	//얼음 녹이기
	while (!meltQ.empty())
	{
		pair<int, int> front = meltQ.front();
		meltQ.pop();
		for (int d = 0; d < 4; d++)
		{
			int tempY = front.first + dy[d];
			int tempX = front.second + dx[d];
			if (checkRange(tempY, tempX) && idx[tempY][tempX] == 0)
			{
				mergeQ.emplace(tempY, tempX);
				idx[tempY][tempX] = idx[front.first][front.second];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	board.assign(R, "");
	parent.assign(R * C, 0);
	idx.assign(R, vector<int>(C, 0));
	int cnt = 1;
	for (int i = 0; i < R; i++)
	{
		cin >> board[i];
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] == '.' || board[i][j] == 'L')
			{
				mergeQ.emplace(i, j);
				idx[i][j] = cnt;
				parent[cnt] = cnt;
				if (board[i][j] == 'L')
				{
					LPos.emplace_back(i, j);
				}
				cnt++;
			}
		}
	}
	while (true)
	{
		//연결된 물끼리 같은 구역으로 판단.
		bfs_merge();
		if (findParent(idx[LPos[0].first][LPos[0].second]) ==
			findParent(idx[LPos[1].first][LPos[1].second]))
		{
			break;
		}
		//얼음 녹이기
		bfs_melt();
		answer++;
	}
	cout << answer << "\n";
	return 0;
}