#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs)
{
	int time = 0, answer = 0, div = jobs.size();
	sort(jobs.rbegin(), jobs.rend());
	// push Time, start time,running time
	queue<pair<int, pair<int, int>>> workerQueue;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> readyQueue;
	while (!jobs.empty() || !workerQueue.empty() || !readyQueue.empty())
	{
		if (!workerQueue.empty() && workerQueue.front().first + workerQueue.front().second.second <= time)
		{
			answer += (workerQueue.front().first + workerQueue.front().second.second) - workerQueue.front().second.first;
			workerQueue.pop();
		}

		while (!jobs.empty() && jobs.back()[0] <= time)
		{
			readyQueue.emplace(jobs.back()[1], jobs.back()[0]);
			jobs.pop_back();
		}

		if (!readyQueue.empty() && workerQueue.empty())
		{
			workerQueue.push({ time, {readyQueue.top().second, readyQueue.top().first} });
			readyQueue.pop();
		}
		time++;
	}
	return answer / div;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//vector<vector<int>> jobs{ {10, 3}, {0, 3}, {4, 3} };
	//vector<vector<int>> jobs{ {0, 3}, {1, 9}, {2, 6} };

	vector<vector<int>> jobs{ {0, 3}, {4, 4}, {5, 3}, {4, 1} };
	cout << solution(jobs) << "\n";
	return 0;
}
