#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	priority_queue<int> keys;
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++)
	{
		q.emplace(i, priorities[i]);
		keys.push(priorities[i]);
	}
	bool flag = true;
	while (!keys.empty() && flag)
	{
		int key = keys.top(); keys.pop();
		while (!q.empty())
		{
			pair<int, int> front = q.front();
			q.pop();
			if (front.second == key)
			{
				if (front.first == location) flag = false;
				break;
			}
			q.push(front);
		}
		answer++;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//vector<int> priorities{ 2, 1, 3, 2 };
	vector<int> priorities{ 1, 1, 9, 1, 1, 1 };
	//int location = 2;
	int location = 0;
	cout << solution(priorities, location) << "\n";
	return 0;
}