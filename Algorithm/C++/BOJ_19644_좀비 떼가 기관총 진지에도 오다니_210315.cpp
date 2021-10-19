#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int L, dist, power, c, cCnt;
bool alive = true;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> L;
	cin >> dist >> power;
	cin >> c;
	while (L--)
	{
		int unit = 0;
		cin >> unit;
		q.push(unit);
	}
	int loop = (dist < q.size()) ? dist : q.size();
	for (int i = 1; i <= loop; i++)
	{
		int front = q.front();
		q.pop();
		int HP = front - (power*i) + (power * cCnt);
		if (HP > 0)
		{
			if (c > 0)
			{
				c--;
				cCnt++;
			}
			else
			{
				alive = false;
				break;
			}
		}
	}
	if (alive)
	{
		while (!q.empty())
		{
			int front = q.front();
			q.pop();
			int HP = front - (power * dist) + (power * cCnt);
			if (HP > 0)
			{
				if (c > 0)
				{
					c--;
					cCnt++;
				}
				else
				{
					alive = false;
					break;
				}
			}
		}
	}
	cout << (alive ? "YES\n" : "NO\n");
	return 0;
}