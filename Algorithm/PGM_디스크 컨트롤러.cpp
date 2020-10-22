#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
	int size = jobs.size();
	int answer = 0;
	int time = 0;
	vector<pair<int, int>> wait;
	sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b)
	{
		return a[0] < b[0];
	});
	while (!jobs.empty() || !wait.empty())
	{
		while (!jobs.empty() && jobs[0][0] <= time)
		{
			wait.emplace_back(jobs[0][1], jobs[0][0]);
			jobs.erase(jobs.begin());
		}
		if (wait.empty() && !jobs.empty())
		{
			time = jobs[0][0];
		}
		else if (!wait.empty())
		{
			sort(wait.begin(), wait.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
				return a.first < b.first;
			});
			answer += ((time + wait[0].first) - wait[0].second);
			time += wait[0].first;
			wait.erase(wait.begin());
		}
	}
	return answer / size;
}