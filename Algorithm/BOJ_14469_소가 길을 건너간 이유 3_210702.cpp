#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, answer;
deque<pair<int, int>> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	dq.assign(N, pair<int, int>(0, 0));
	for (int i = 0; i < N; i++) cin >> dq[i].first >> dq[i].second;
	sort(dq.begin(), dq.end());
	while (!dq.empty())
	{
		pair<int, int> front = dq.front(); dq.pop_front();
		answer = ((answer <= front.first) ? front.first + front.second : answer + front.second);
	}
	cout << answer << "\n";
	return 0;
}