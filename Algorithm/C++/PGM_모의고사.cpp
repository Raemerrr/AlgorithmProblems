#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> cnt{ 0,0,0 };
	vector<int> pattern1{ 1, 2, 3, 4, 5 };
	vector<int> pattern2{ 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> pattern3{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	for (int i = 0; i < answers.size(); i++)
	{
		if (pattern1[i%pattern1.size()] == answers[i]) {
			cnt[0]++;
		}
		if (pattern2[i%pattern2.size()] == answers[i]) {
			cnt[1]++;
		}
		if (pattern3[i%pattern3.size()] == answers[i]) {
			cnt[2]++;
		}
	}
	int maxCnt = max(cnt[0], max(cnt[1], cnt[2]));
	for (int i = 0; i < cnt.size(); i++)
	{
		if (cnt[i] == maxCnt) { answer.push_back(i + 1); }
	}
	return answer;
}