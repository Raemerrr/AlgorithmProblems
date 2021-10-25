#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	bool flag = false;
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
	while (true)
	{
		int first = pq.top(); pq.pop();
		if (K <= first || pq.empty())
		{
			flag = (K <= first);
			break;
		}
		int second = pq.top(); pq.pop();
		pq.push(first + (second * 2));
		answer++;
	}
	return ((flag) ? answer : -1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//vector<int> scoville{ 1, 2, 3, 9, 10, 12 };
	vector<int> scoville{ 1, 2, 3 };
	//int K = 7;
	int K = 11;
	cout << solution(scoville, K) << "\n";
	return 0;
}