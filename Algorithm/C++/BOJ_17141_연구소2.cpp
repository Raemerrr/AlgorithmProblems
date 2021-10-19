#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans, emptyCount;
vector<vector<int>> map;
//���̷����� ������ �ִ� ��ġ (2�� ��ġ)
vector<pair<int, int>> mPos;
//mPos�� ���� �ε��� ����
vector<vector<int>> combi;
vector<int> tempCombi;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

bool wallCheck(const int y, const int x)
{
	if (y >= 0 && x >= 0 && y < N && x < N)
	{
		return true;
	}
	return false;
}

void combination(const int index)
{
	if (tempCombi.size() == M)
	{
		combi.emplace_back(tempCombi);
	}
	else
	{
		for (int i = index; i < mPos.size(); i++)
		{
			tempCombi.emplace_back(i);
			combination(i + 1);
			tempCombi.pop_back();
		}
	}
}

void Proc()
{
	for (const auto& d : combi)
	{
		//�ӽ� ��
		vector<vector<int>> tMap = map;
		queue<pair<int, int>> q;
		int tempEmptyCount = emptyCount - M;
		int cnt = 0;
		for (const auto& z : d)
		{
			tMap[mPos[z].first][mPos[z].second] = 2;
			q.emplace(mPos[z].first, mPos[z].second);
		}
		while (!q.empty() && tempEmptyCount > 0)
		{
			for (int i = 0, size = q.size(); i < size; i++)
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int d = 0; d < 4; d++)
				{
					int tempY = y + dy[d];
					int tempX = x + dx[d];
					if (wallCheck(tempY, tempX) && tMap[tempY][tempX] == 0)
					{
						q.emplace(tempY, tempX);
						tMap[tempY][tempX] = 2;
						tempEmptyCount--;
					}
				}
			}
			cnt++;
			if (ans < cnt)
			{
				break;
			}
		}
		//��ĭ�� �����ϹǷ� ������ ó���� �� ����.
		if (tempEmptyCount == 0)
		{
			ans = (ans < cnt) ? ans : cnt;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(N, 0));
	ans = N * N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				emptyCount++;
			}
			else if (map[i][j] == 2)
			{
				mPos.emplace_back(i, j);
				//�̸� �̵� ������ ���� �����
				map[i][j] = 0;
				emptyCount++;
			}
		}
	}
	combination(0);
	Proc();
	if (ans == (N*N))
	{
		cout << "-1\n";
	}
	else
	{
		cout << ans << "\n";
	}
	return 0;
}