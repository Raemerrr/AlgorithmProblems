#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Texi
{
	int y;
	int x;
	Texi() { y = -1; x = -1; }
	Texi(const int y, const int x) :y(y), x(x) {}
};

struct Passenger
{
	int y;
	int x;
	bool isArrive;
	Passenger() { y = -1; x = -1; isArrive = false; }
	Passenger(const int y, const int x) :y(y), x(x), isArrive(false) {}
};

//F - ����
int N, M, F;
vector<vector<int>> board;
Texi T;
//start
map<int, Passenger> s;
//end
map<int, Passenger> e;
//����
int dy[] = { 0,0,1,0,-1 };
int dx[] = { 0,1,0,-1,0 };
vector<vector<bool>> visited;

bool CheckWall(const int y, const int x)
{
	if (y > 0 && x > 0 && y <= N && x <= N)
	{
		return true;
	}
	return false;
}

bool Moving(const Texi t_T, const int index)
{
	queue<Texi> q;
	q.emplace(t_T);
	visited[t_T.y][t_T.x] = true;
	int dist = 0;
	while (true)
	{
		for (int i = 0, size = q.size(); i < size; i++)
		{
			Texi front = q.front();
			q.pop();
			//�̵� �� ���ᰡ �����ϴٸ�..
			if (F < 1)
			{
				cout << "-1\n";
				return false;
			}
			//���� �°� ž�� �Ŀ� �ڽ��� �ڸ��� Ž������ ���� 1 ~ 4
			for (int d = 1; d < 5; d++)
			{
				int tempY = front.y + dy[d];
				int tempX = front.x + dx[d];
				if (CheckWall(tempY, tempX) && !visited[tempY][tempX]
					&& board[tempY][tempX] != -1)
				{
					visited[tempY][tempX] = true;
					//�ش� �°� ���������
					if (e[index].y == tempY && e[index].x == tempX)
					{
						//return �� ���� �Ҹ� ���ϱ� ������ �Ҹ�
						F--;
						dist++;
						//�°� ���������� ���ᰡ 0���� �����ص� �����ϱ� ����
						if (F < 0)
						{
							cout << "-1\n";
							return false;
						}
						F += (dist * 2);
						return true;
					}
					q.emplace(Texi(tempY, tempX));
				}
			}
		}
		F--;
		dist++;
		//�ýð� �մ��� �¿����� ���� ������ ������ �����ִٸ�...
		if (q.empty() && !s[index].isArrive)
		{
			cout << "-1\n";
			return false;
		}
	}
}

void Proc()
{
	queue<Texi> q;
	q.emplace(T);
	//���� ���� ã��
	while (!q.empty() && F > 0 && M > 0)
	{
		//�°� �켱������ ������ ����.
		vector<pair<int, int>> v;
		//�ٸ� �°��� ������������ ����ϴ� �����
		bool flag = false;
		for (int i = 0, size = q.size(); i < size; i++)
		{
			Texi front = q.front();
			q.pop();
			//�°����� ���� �� ���ᰡ �ٴ� �� ��Ȳ
			if (F < 1)
			{
				cout << "-1\n";
				return;
			}
			for (int d = 0; d < 5; d++)
			{
				int tempY = front.y + dy[d];
				int tempX = front.x + dx[d];
				if (CheckWall(tempY, tempX) && !visited[tempY][tempX]
					&& board[tempY][tempX] != -1)
				{
					visited[tempY][tempX] = true;
					int index = board[tempY][tempX];
					//���� �������� ���� �°� �ڸ���� 
					if (index > 0 && !s[index].isArrive && s[index].y == tempY && s[index].x == tempX)
					{
						v.emplace_back(tempY, tempX);
						//���� ��ġ�� ���� ó���� ����...
						if (d == 0)
						{
							flag = true;
							break;
						}
					}
					q.emplace(Texi(tempY, tempX));
				}
			}
			//���� ��ġ�� ���� ó���� ����...
			if (flag)
			{
				break;
			}
		}
		//�ý� ���� �Ҹ� - ���� ��ġ�� ���� �Ҹ� ���� ����...
		if (!flag)
		{
			F--;
		}
		//�°��� �ִٸ�
		if (!v.empty())
		{
			//������ ���� false ó��
			visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
			//�־��� �켱������ �������� ����
			sort(v.begin(), v.end());
			//q�� ���� ���� �°� ���������� ����ϱ� ����
			while (!q.empty())
			{
				q.pop();
			}
			int index = board[v[0].first][v[0].second];
			int tempY = e[index].y;
			int tempX = e[index].x;
			//�ý� �̵� �Լ�
			if (!Moving(Texi(v[0].first, v[0].second), index)) { return; };
			//���� ����
			s[index].isArrive = true;
			//���� ��� ��ġ ����
			q.emplace(Texi(tempY, tempX));
			//������ ���� false ó��
			visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
			//��� �°� �� ���̱�
			M--;
		}
		//q�� ����µ� �մ��� �����ִٸ� - ������ ���� �Ѿ�� ���ϴ� ��Ȳ
		if (q.empty() && M > 0)
		{
			cout << "-1\n";
			return;
		}
	}
	cout << F << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> F;
	board = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int num = 0;
			cin >> num;
			// ** ���� -1 ó��
			board[i][j] = num * -1;
		}
	}

	cin >> T.y >> T.x;
	for (int i = 1; i <= M; i++)
	{
		int sY = 0, sX = 0, eY = 0, eX = 0;
		cin >> sY >> sX >> eY >> eX;
		board[sY][sX] = i;
		s[i] = Passenger(sY, sX);
		e[i] = Passenger(eY, eX);
	}
	Proc();
	return 0;
}