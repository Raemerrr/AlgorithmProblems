#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
	int answer = 0, currentTime = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jobsQ;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 시작 시간 순으로 jobsQ에서 꺼내기 위한 입력
	for (int i = 0; i < jobs.size(); i++) jobsQ.emplace(jobs[i][0], jobs[i][1]);
	while (!(jobsQ.empty() && pq.empty()))
	{
		bool flag = false;
		// 현재 작업 시각에 실행할 수 있는 작업을 pq에 넣는 작업
		while (!jobsQ.empty() && jobsQ.top().first <= currentTime)
		{
			pq.emplace(jobsQ.top().second, jobsQ.top().first);
			jobsQ.pop();
		}
		// 여기서 while문을 쓰지 않은 것은 작업 후 시간 값이 변경되어 jobsQ에서 pq로 들어 올 내용이 더 있을 수 있다.!!
		if (!pq.empty())
		{
			pair<int, int> d = pq.top(); pq.pop();
			currentTime += d.first;
			answer += (currentTime - d.second);
			flag = true;
		}
		currentTime += ((flag) ? 0 : 1);
	}
	return answer / jobs.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>> jobs{ {0, 3},{1, 9},{2, 6} };
	cout << solution(jobs) << "\n";
	return 0;
}