#include <iostream>
#include <deque>

using namespace std;

int N;
deque<pair<int, int>> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num = 0;
		cin >> num;
		dq.push_back({ i,num });
	}
	//가장 앞 1번 처리
	cout << dq.front().first << " ";
	int loop = dq.front().second;
	dq.pop_front();
	while (!dq.empty())
	{
		if (loop < 0)
		{
			loop *= -1;
			loop -= 1;
			if (loop > dq.size())
			{
				if (loop % dq.size() == 0)
				{
					loop = dq.size();
				}
				else
				{
					loop = loop % dq.size();
				}
			}
			while (loop--)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cout << dq.back().first << " ";
			loop = dq.back().second;
			dq.pop_back();
		}
		//loop가 양수
		else
		{
			loop -= 1;
			if (loop > dq.size())
			{
				if (loop % dq.size() == 0)
				{
					loop = dq.size();
				}
				else
				{
					loop = loop % dq.size();
				}
			}
			while (loop--)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			cout << dq.front().first << " ";
			loop = dq.front().second;
			dq.pop_front();
		}
	}
	return 0;
}