#include <iostream>
#include <string>
#include <deque>

using namespace std;

int N, L;
deque<int> input;
deque<pair<int, int>> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L;
	input.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> input[i];
	for (int i = 0; i < N; i++) {
		if (!dq.empty() && dq.front().second + L - 1 < i)
		{
			dq.pop_front();
		}

		while (!dq.empty() && input[i] <= dq.back().first)
		{
			dq.pop_back();
		}
		dq.emplace_back(input[i], i);
		cout << dq.front().first << " ";
	}
	cout << "\n";
	return 0;
}