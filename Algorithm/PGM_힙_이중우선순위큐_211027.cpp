#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer(2, 0);
	map<int, int> maxMap, minMap;
	priority_queue<int> maxQ;
	priority_queue<int, vector<int>, greater<int>> minQ;
	for (const string d : operations) {
		if (d[0] == 'I')
		{
			int i = stoi(d.substr(2, d.size()));
			minQ.push(i);
			maxQ.push(i);
		}
		else if (d == "D 1")
		{
			while (!maxQ.empty() && maxMap.count(maxQ.top()) && 0 < maxMap[maxQ.top()])
			{
				maxMap[maxQ.top()]--;
				if (maxMap[maxQ.top()] == 0)
				{
					maxMap.erase(maxQ.top());
				}
				maxQ.pop();
			}
			if (!maxQ.empty())
			{
				minMap[maxQ.top()]++;
				maxQ.pop();
			}
		}
		else //if (d == "D -1")
		{
			while (!minQ.empty() && minMap.count(minQ.top()) && 0 < minMap[minQ.top()])
			{
				minMap[minQ.top()]--;
				if (minMap[minQ.top()] == 0)
				{
					minMap.erase(minQ.top());
				}
				minQ.pop();
			}
			if (!minQ.empty())
			{
				maxMap[minQ.top()]++;
				minQ.pop();
			}
		}
	}
	while (!maxQ.empty() && 0 < maxMap[maxQ.top()])
	{
		maxMap[maxQ.top()]--;
		if (maxMap[maxQ.top()] == 0)
		{
			maxMap.erase(maxQ.top());
		}
		maxQ.pop();
	}
	while (!minQ.empty() && 0 < minMap[minQ.top()])
	{
		minMap[minQ.top()]--;
		if (minMap[minQ.top()] == 0)
		{
			minMap.erase(minQ.top());
		}
		minQ.pop();
	}
	if (!maxQ.empty())
	{
		answer[0] = maxQ.top();
	}
	if (!minQ.empty())
	{
		answer[1] = minQ.top();
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//vector<string> operations{ "I 7","I 5","I -5","D -1", "I -8", "D 1", "D 1", "D 1" };
	vector<string> operations{ "I 7","I 5","I -5","D -1" };
	for (const int d : solution(operations)) {
		cout << d << " ";
	}
	cout << "\n";
	return 0;
}