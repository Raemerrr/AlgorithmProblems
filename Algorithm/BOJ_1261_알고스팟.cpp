#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int N, M;
//���� ������ �����ϴ� �� ����
vector<string> map;
//���� ���� �湮 �� ���� ���� ���� üũ�ϴ� ����
vector<vector<int>> check;
//�湮���� ����
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

//�湮 ������ �������� üũ
bool wallCheck(const int y, const int x)
{
	if (y > -1 && y < M && x > -1 && x < N)
	{
		return true;
	}
	return false;
}

void Proc()
{
	//������ 0,0 ���� �湮�ϵ��� ������.
	queue<pair<pair<int, int>, int>> q;
	q.emplace(make_pair(0, 0), 0);
	while (!q.empty())
	{
		pair<int, int> pos = q.front().first;
		int cnt = q.front().second;
		q.pop();
		//���� �湮 ����� ���� �湮 ��Ϻ��� �۴ٸ�
		if (check[pos.first][pos.second] <= cnt)
		{
			continue;
		}
		//���� �湮 ����� ���� �湮 ��Ϻ��� ������ ���� 
		check[pos.first][pos.second] = cnt;
		for (int i = 0; i < 4; i++)
		{
			int tempY = pos.first + dy[i];
			int tempX = pos.second + dx[i];
			//�湮�� ������ ��������
			if (wallCheck(tempY, tempX))
			{
				int currCnt = cnt + (map[tempY][tempX] - '0');
				//���� �湮 ��ϰ� ����(?)�湮 ����� üũ ��Ϻ��� �۴ٸ�
				if (check[tempY][tempX] > currCnt)
				{
					q.emplace(make_pair(tempY, tempX), currCnt);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	check = vector<vector<int>>(M, vector<int>(N, N * M));
	map = vector<string>(M, "");
	for (int i = 0; i < M; i++)
	{
		cin >> map[i];
	}
	Proc();
	cout << check[M - 1][N - 1];
}