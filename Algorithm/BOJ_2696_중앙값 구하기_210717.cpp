#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0; cin >> test_case;
	while (test_case--)
	{
		priority_queue<int> minQ;
		priority_queue<int, vector<int>, greater<int>> maxQ;
		vector<int> answer;
		int N = 0, center = 0, num = 0; cin >> N >> num;
		center = num;
		answer.push_back(center);
		for (int i = 1; i < N; i++)
		{
			cin >> num;
			if (center < num) maxQ.push(num);
			else minQ.push(num);
			//문제에서 의미하는 홀수번째는 인덱스로 짝수일 경우
			if (i % 2 == 0)
			{
				if (minQ.size() < maxQ.size())
				{
					minQ.push(center);
					center = maxQ.top();
					maxQ.pop();
				}
				else if (minQ.size() > maxQ.size())
				{
					maxQ.push(center);
					center = minQ.top();
					minQ.pop();
				}
				answer.push_back(center);
			}
		}
		cout << answer.size() << "\n";
		for (const int d : answer) { cout << d << " "; }cout << "\n";
	}
	return 0;
}