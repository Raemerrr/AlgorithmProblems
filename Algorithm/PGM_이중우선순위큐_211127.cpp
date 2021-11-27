#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer{ 0,0 };
	priority_queue<int, vector<int>, greater<int>> minQ;
	priority_queue<int> maxQ;
	set<int> maxSet, minSet;
	for (const string& d : operations)
	{
		char operation = d[0];
		int num = stoi(d.substr(2, d.size()));
		if (operation == 'I')
		{
			maxQ.emplace(num);
			minQ.emplace(num);
		}
		else
		{
			if (num == 1)
			{
				if (!maxQ.empty())
				{
					while (!maxQ.empty() && maxSet.count(maxQ.top()))
					{
						maxSet.erase(maxQ.top());
						maxQ.pop();
					}
					if (!maxQ.empty())
					{
						minSet.insert(maxQ.top());
						maxQ.pop();
					}
				}
			}
			else
			{
				if (!minQ.empty())
				{
					while (!minQ.empty() && minSet.count(minQ.top()))
					{
						minSet.erase(minQ.top());
						minQ.pop();
					}
					if (!minQ.empty())
					{
						maxSet.insert(minQ.top());
						minQ.pop();
					}
				}
			}
		}
	}
	while (!maxQ.empty() && maxSet.count(maxQ.top()))
	{
		maxSet.erase(maxQ.top());
		maxQ.pop();
	}
	while (!minQ.empty() && minSet.count(minQ.top()))
	{
		minSet.erase(minQ.top());
		minQ.pop();
	}
	answer[0] = ((!maxQ.empty()) ? maxQ.top() : 0);
	answer[1] = ((!minQ.empty()) ? minQ.top() : 0);
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//vector<string> v{ "I 16", "D 1" };
	//vector<string> v{ "I 7", "I 5", "I -5", "D -1" };
	vector<string> v{ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };
	for (const int d : solution(v)) {
		cout << d << " ";
	}
	cout << "\n";
	return 0;
}