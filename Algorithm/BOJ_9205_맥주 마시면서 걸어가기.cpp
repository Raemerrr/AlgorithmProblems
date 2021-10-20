#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int, int> P;
vector<P> pos;
vector<vector<int>> v;
vector<vector<int>> dp;
vector<vector<bool>> visited;
int N;
bool flag;

//�� ���� �� �Ÿ� ���
void distanceCalc()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			//v[i][j] == 0 : �Ÿ� ����� ����� ���ٸ� ���
			if (v[i][j] == 0 && i != j)
			{
				//�� ������ �Ÿ� |y1-y2| + |x1-x2|
				int dist = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
				v[i][j] = dist;
				v[j][i] = dist;
			}
		}
	}
}

void dfs(int index)
{
	if (index == N - 1)
	{
		flag = true;
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			//!flag : �佺Ƽ���� ������ ���� ���ٸ�
			//v[index][i] <= 1000 : �ִ� ���� �Ÿ�
			if (!flag && index != i && !visited[index][i] && v[index][i] <= 1000)
			{
				visited[index][i] = true;
				visited[i][index] = true;
				dfs(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		cin >> N;
		//�ʱ�ȭ
		N += 2;
		pos.clear();
		v = vector<vector<int>>(N, vector<int>(N, 0));
		dp = vector<vector<int>>(N, vector<int>(N, 0));
		visited = vector<vector<bool>>(N, vector<bool>(N, false));
		flag = false;
		//��ǥ ����
		for (int i = 0; i < N; i++)
		{
			int y = 0, x = 0;
			cin >> y >> x;
			pos.emplace_back(y, x);
		}
		//�� ����(?)���� ���ΰ��� �Ÿ��� ���
		distanceCalc();
		//����̳� ������ ���!
		dfs(0);

		//�佺Ƽ���� ���� ������
		if (flag)
		{
			cout << "happy\n";
		}
		//�佺Ƽ���� �������� ���ߴٸ�
		else
		{
			cout << "sad\n";
		}
	}
	return 0;
}