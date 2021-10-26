#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
	int answer = 0, currentTime = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jobsQ;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// ���� �ð� ������ jobsQ���� ������ ���� �Է�
	for (int i = 0; i < jobs.size(); i++) jobsQ.emplace(jobs[i][0], jobs[i][1]);
	while (!(jobsQ.empty() && pq.empty()))
	{
		bool flag = false;
		// ���� �۾� �ð��� ������ �� �ִ� �۾��� pq�� �ִ� �۾�
		while (!jobsQ.empty() && jobsQ.top().first <= currentTime)
		{
			pq.emplace(jobsQ.top().second, jobsQ.top().first);
			jobsQ.pop();
		}
		// ���⼭ while���� ���� ���� ���� �۾� �� �ð� ���� ����Ǿ� jobsQ���� pq�� ��� �� ������ �� ���� �� �ִ�.!!
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