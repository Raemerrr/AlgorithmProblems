#include <iostream>
#include <deque>

using namespace std;

int N, L;
deque<pair<int, int>> dq;
deque<int> input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L;
	input.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}
	for (int i = 0; i < N; i++)
	{
		//���� ���� �� ó��
		if (!dq.empty() && i >= dq.front().second + L)
		{
			dq.pop_front();
		}
		//���� ���� �� ó��
		while (!dq.empty() && dq.back().first >= input[i])
		{
			dq.pop_back();
		}
		dq.push_back({ input[i], i });
		cout << dq.front().first << " ";
	}
	return 0;
}