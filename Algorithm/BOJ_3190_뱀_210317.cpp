#include <iostream>
#include <deque>
#include <map>

using namespace std;

enum direction
{
	North,
	East,
	South,
	West
};

struct snake
{
	int y;
	int x;
	direction dir;
	snake(const int y, const int x, const direction dir) : y(y), x(x), dir(dir) {}
};

int N, K, L;
deque<snake> dq;
map<pair<int, int>, bool> applePos;
map<pair<int, int>, bool> collisionCheck;
map<int, char> timeEffect;

pair<int, int> getAddPos(const direction& dir) {
	if (dir == North)
	{
		return pair<int, int>(-1, 0);
	}
	else if (dir == East)
	{
		return pair<int, int>(0, 1);
	}
	else if (dir == South)
	{
		return pair<int, int>(1, 0);
	}
	else// if (dir == West)
	{
		return pair<int, int>(0, -1);
	}
}

direction dirChange(const snake& s, char dir) {
	if (dir == 'D')
	{
		if (s.dir == North)
		{
			return East;
		}
		else if (s.dir == East)
		{
			return South;
		}
		else if (s.dir == South)
		{
			return West;
		}
		else// if (s.dir == West)
		{
			return North;
		}
	}
	else
	{
		if (s.dir == North)
		{
			return West;
		}
		else if (s.dir == East)
		{
			return North;
		}
		else if (s.dir == South)
		{
			return East;
		}
		else// if (s.dir == West)
		{
			return South;
		}
	}
}

bool checkRange(const int y, const int x) {
	if (0 < x && 0 < y && x <= N && y <= N)
	{
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	dq.push_back(snake(1, 1, East));
	collisionCheck[{1, 1}] = true;
	cin >> N;
	cin >> K;
	while (K--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		applePos[{a, b}] = true;
	}
	cin >> L;
	while (L--)
	{
		int a = 0; char c = ' ';
		cin >> a >> c;
		timeEffect[a] = c;
	}
	int timer = 0;
	while (true)
	{
		snake head = dq.front();
		if (timeEffect.count(timer))
		{
			head.dir = dirChange(head, timeEffect[timer]);
		}
		timer++;
		pair<int, int> addPos = getAddPos(head.dir);
		snake Next(head.y + addPos.first, head.x + addPos.second, head.dir);
		//종료 조건 - 범위를 나가거나 뱀의 몸에 부딪힌 경우
		if (!checkRange(Next.y, Next.x) || collisionCheck.count({ Next.y,Next.x }))
		{
			break;
		}
		dq.push_front(Next);
		collisionCheck[{Next.y, Next.x}] = true;
		//사과가 없다면 꼬리 자르기
		if (!applePos.count({ Next.y, Next.x }))
		{
			collisionCheck.erase({ dq.back().y, dq.back().x });
			dq.pop_back();
		}
		//사과가 있다면 사과 지우기
		else
		{
			applePos.erase({ Next.y, Next.x });
		}
	}
	cout << timer << "\n";
	return 0;
}