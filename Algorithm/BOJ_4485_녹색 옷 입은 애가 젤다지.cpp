#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 10000000;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

int N, ans, test_case = 1;
vector<vector<int>> board;
vector<vector<int>> dp;

//���� �Ǵ� �Լ�
bool checkRange(const int y, const int x)
{
	if (y > -1 && x > -1 && y < N && x < N)
	{
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}
		//������ǵ��� ���� �����ϱ� ���� ����
		board = vector<vector<int>>(N, vector<int>(N, 0));
		//������ ���� �����ϱ� ���� ����
		dp = vector<vector<int>>(N, vector<int>(N, INF));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
			}
		}

		priority_queue<pair<int, pair<int, int>>> pq;
		//�������� 0,0 ���� board[0][0]
		pq.emplace(board[0][0], pair<int, int>(0, 0));
		//���� �� �Է�
		dp[0][0] = board[0][0];
		while (!pq.empty())
		{
			//�ּ��� ���� ó�� -
			int cost = -pq.top().first;
			//���� ��ġ
			pair<int, int> pos = pq.top().second;
			pq.pop();
			for (int i = 0; i < 4; i++)
			{
				int tempY = pos.first + dy[i];
				int tempX = pos.second + dx[i];
				//�湮�� ������ ��ġ���� ������ ���� ���ߴٸ�
				if (checkRange(tempY, tempX) && dp[tempY][tempX] > dp[pos.first][pos.second] + board[tempY][tempX])
				{
					dp[tempY][tempX] = dp[pos.first][pos.second] + board[tempY][tempX];
					pq.emplace(-dp[tempY][tempX], pair<int, int>(tempY, tempX));
				}
			}
		}
		cout << "Problem " << test_case << ": " << dp[N - 1][N - 1] << "\n";
		test_case++;
	}

	return 0;
}