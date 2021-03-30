#include <iostream>
#include <deque>

using namespace std;

int N, K, M, cnt;
deque<int> dq;
bool reverseFlag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> M;
	K -= 1;
	dq.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		dq[i] = i + 1;
	}
	while (!dq.empty())
	{
		int loop = K - 1;
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
		if (reverseFlag)
		{
			while (loop > 0)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				loop--;
			}
			cout << dq.back() << "\n";
			dq.pop_back();
			cnt++;
		}
		//앞에서 뒤로 넣기
		else
		{
			while (loop > 0)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				loop--;
			}
			cout << dq.front() << "\n";
			dq.pop_front();
			cnt++;
		}
		if (cnt == M)
		{
			reverseFlag = !reverseFlag;
			cnt = 0;
		}
	}
	return 0;
}