#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int MAX = 20 + 1;
class Shark
{
public:
	int y;
	int x;
	int dir;
	bool alive;
	vector<vector<int>> priority;

	Shark() {
		y = -1;
		x = -1;
		dir = -1;
		alive = false;
		priority = vector<vector<int>>(4, vector<int>(4, -1));
	}

	Shark(int y, int x, bool alive) : y(y), x(x), alive(alive)
	{
		//dir은 생성 단계에서 입력하지 않음.
		dir = -1;
		priority = vector<vector<int>>(4, vector<int>(4, -1));
	}
};

int N, M, k, ans, sharkCnt;

//현재 위치에 위치한 상어 
vector<int> board[MAX][MAX];
pair<int, int> smell[MAX][MAX];
map<int, Shark> sharks;
enum direction { none = -1, _up, _down, _left, _right };

bool CheckWall(const int y, const int x)
{
	if (y >= 0 && x >= 0 && y < N && x < N)
	{
		return true;
	}
	return false;
}

pair<int, int> getPos(const direction d)
{
	if (d == _up)
	{
		return pair<int, int>(-1, 0);
	}
	else if (d == _down)
	{
		return pair<int, int>(1, 0);
	}
	else if (d == _left)
	{
		return pair<int, int>(0, -1);
	}
	else if (d == _right)
	{
		return pair<int, int>(0, 1);
	}
	else
	{
		return pair<int, int>(0, 0);
	}
}

void Proc()
{
	while (ans <= 1000 && sharkCnt > 1)
	{
		//이동시 한 칸에 1마리의 상어만 존재 하는 것으로 간주
		for (int i = 1; i <= M; i++)
		{
			//존재하는 상어만 이동
			if (sharks[i].alive)
			{
				bool flag = false;
				//우선순위를 따라 주변을 살피기
				pair<int, int> flagPos = pair<int, int>(-1, -1);
				int flagDir = -1;
				for (int d = 0; d < 4; d++)
				{
					int curDir = sharks[i].priority[sharks[i].dir][d];
					pair<int, int> tPos = getPos(static_cast<direction>(curDir));
					int tempY = sharks[i].y + tPos.first;
					int tempX = sharks[i].x + tPos.second;
					if (CheckWall(tempY, tempX))
					{
						//가용 범위 내 냄새가 없는 칸이라면
						if (smell[tempY][tempX].first == 0)
						{
							//현재 칸 비우기
							board[sharks[i].y][sharks[i].x].pop_back();
							//이동 한 칸으로 넣기
							board[tempY][tempX].push_back(i);
							sharks[i].y = tempY;
							sharks[i].x = tempX;
							sharks[i].dir = curDir;
							flag = true;
							break;
						}
						//가용 범위 내 나의 냄새가 있다면 임시 저장
						else if (smell[tempY][tempX].first == i && flagPos == pair<int, int>(-1, -1))
						{
							flagPos = pair<int, int>(tempY, tempX);
							flagDir = curDir;
						}
					}
				}
				//사방이 모두 냄새로 가득 찼다면 - 내번호 찾아가기.
				if (!flag)
				{
					//내 번호가 있다는 가정...
					if (flagPos != pair<int, int>(-1, -1))
					{
						//현재 칸 비우기
						board[sharks[i].y][sharks[i].x].pop_back();
						//이동 한 칸으로 넣기
						board[flagPos.first][flagPos.second].push_back(i);
						sharks[i].y = flagPos.first;
						sharks[i].x = flagPos.second;
						sharks[i].dir = flagDir;
					}
					// 없다면..? 어떤 처리 해야하는지..? - 해당 사항 없는듯..?
					else { cout << "[" << i << "] 상어 갈 곳이 엄슴...\n"; }
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (smell[i][j].second > 0)
				{
					smell[i][j].second--;
					if (smell[i][j].second == 0)
					{
						smell[i][j].first = 0;
					}
				}
			}
		}

		//이동 후 냄새 뿌리기  & 한칸에 2마리 이상 있는 곳 처리
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int size = board[i][j].size();
				if (size > 0)
				{
					if (size > 1)
					{
						sort(board[i][j].begin(), board[i][j].end());
						for (int z = size - 1; z > 0; z--)
						{
							//상어 죽음 처리..
							sharks[board[i][j][z]].alive = false;
							board[i][j].pop_back();
							sharkCnt--;
						}
					}
					smell[i][j].first = board[i][j][0];
					smell[i][j].second = k;
				}
			}
		}
		ans++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> k;
	sharkCnt = M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int index = 0;
			cin >> index;
			if (index != 0)
			{
				board[i][j].push_back(index);
				//맨처음 자기 위치에 냄새뿌린다.
				smell[i][j].first = index;
				smell[i][j].second = k;
				sharks[index] = Shark(i, j, true);
			}
		}
	}
	for (int i = 1; i <= M; i++)
	{
		int t_dir = 0;
		cin >> t_dir;
		t_dir--;
		sharks[i].dir = t_dir;
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int z = 0; z < 4; z++)
			{
				int t_dir = 0;
				cin >> t_dir;
				t_dir--;
				sharks[i].priority[j][z] = t_dir;
			}
		}
	}
	Proc();
	if (ans > 1000)
	{
		cout << "-1\n";
	}
	else
	{
		cout << ans << "\n";
	}
	return 0;
}