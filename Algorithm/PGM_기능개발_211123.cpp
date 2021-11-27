#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	queue<pair<int, int>> q;
	for (int i = 0; i < progresses.size(); i++)
	{
		q.emplace(progresses[i], speeds[i]);
	}
	int day = 1;
	while (!q.empty())
	{
		int cnt = 0;
		while (!q.empty() && q.front().second * day + q.front().first >= 100)
		{
			cnt++;
			q.pop();
		}
		if (cnt > 0)
		{
			answer.push_back(cnt);
		}
		day++;
	}
	return answer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//vector<int> progresses{ 93,30,55 };
	vector<int> progresses{ 95, 90, 99, 99, 80, 99 };
	//vector<int> speeds{ 1,30,5 };
	vector<int> speeds{ 1, 1, 1, 1, 1, 1 };
	for (const int d : solution(progresses, speeds)) {
		cout << d << " ";
	}
	cout << "\n";
	return 0;
}