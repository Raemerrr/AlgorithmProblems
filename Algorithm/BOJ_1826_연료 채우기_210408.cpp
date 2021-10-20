#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, P, answer;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqASC;
priority_queue<pair<int, int>> pqDESC;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		pqASC.emplace(a, b);
	}
	cin >> L >> P;
	while (P < L)
	{
		while (!pqASC.empty() && pqASC.top().first <= P) {
			pqDESC.emplace(pqASC.top().second, pqASC.top().first);
			pqASC.pop();
		}
		if (pqDESC.empty())
		{
			answer = -1;
			break;
		}
		P += pqDESC.top().first;
		pqDESC.pop();
		answer++;
	}
	cout << answer << "\n";
	return 0;
}
