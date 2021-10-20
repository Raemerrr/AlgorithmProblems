#include <iostream>
#include <vector>
#include <string>
#include <queue>

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
		int N = 0, center = 0; cin >> N >> center; answer.push_back(center);
		for (int i = 0; i < N - 1; i++)
		{
			int num = 0; cin >> num;
			if (center < num)
			{
				maxQ.push(num);
			}
			else
			{
				minQ.push(num);
			}
			// È¦¼ö¶ó¸é
			if (i & 1)
			{
				if (minQ.size() < maxQ.size())
				{
					minQ.push(center);
					center = maxQ.top();
					maxQ.pop();
				}
				else if (maxQ.size() < minQ.size())
				{
					maxQ.push(center);
					center = minQ.top();
					minQ.pop();
				}
				answer.push_back(center);
			}
		}
		cout << answer.size() << "\n";
		for (int i = 1; i < answer.size() + 1; i++)
		{
			cout << answer[i - 1] << " ";
			if (i < answer.size() && i % 10 == 0)
			{
				cout << "\n";
			}
		}
		cout << "\n";
	}
	return 0;
}