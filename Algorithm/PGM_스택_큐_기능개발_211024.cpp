#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> progressesQ, speedsQ;
	int cnt = 0;
	for (int i = 0; i < progresses.size(); i++)
	{
		progressesQ.push(progresses[i]);
		speedsQ.push(speeds[i]);
	}
	while (!progressesQ.empty() && !speedsQ.empty())
	{
		//top * cnt
		int answerCnt = 0;
		while (!progressesQ.empty() && !speedsQ.empty() && 100 <= progressesQ.front() + (speedsQ.front() * cnt))
		{
			progressesQ.pop();
			speedsQ.pop();
			answerCnt++;
		}
		if (0 < answerCnt)
		{
			answer.push_back(answerCnt);
		}
		cnt++;
	}
	return answer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> progresses{ 93, 30, 55 };
	vector<int> speeds{ 1, 30, 5 };
	for (const int d : solution(progresses, speeds)) {
		cout << d << " ";
	}
	cout << "\n";
	return 0;
}