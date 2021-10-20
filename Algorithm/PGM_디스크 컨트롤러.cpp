#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
	int size = jobs.size();
	int answer = 0;
	int time = 0;
	priority_queue<pair<int, int>> wait;
	sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b)
	{
		return a[0] < b[0];
	});
	while (!jobs.empty() || !wait.empty())
	{
		while (!jobs.empty() && jobs[0][0] <= time)
		{
			wait.emplace(-jobs[0][1], jobs[0][0]);
			jobs.erase(jobs.begin());
		}
		if (wait.empty() && !jobs.empty())
		{
			time = jobs[0][0];
		}
		else if (!wait.empty())
		{
			pair<int, int> top = wait.top();
			answer += ((time + (-top.first)) - top.second);
			time += -top.first;
			wait.pop();
		}
	}
	return answer / size;
}