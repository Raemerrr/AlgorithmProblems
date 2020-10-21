#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> temp;
	for (int i = 0; i < progresses.size(); i++)
	{
		//미리 완료 일자를 계산한다.
		temp.push_back(static_cast<int>(ceil((100.0f - progresses[i]) / speeds[i])));
	}
	//가장 첫 번째 값부터 시작한다.
	int num = temp[0];
	while (!temp.empty())
	{
		int cnt = 0;
		while (!temp.empty() && num >= temp[0])
		{
			temp.erase(temp.begin());
			cnt++;
		}
		//현재 가장 큰 값은 0번 인덱스에 있는 값이다.
		if (!temp.empty()) { num = temp[0]; }
		answer.emplace_back(cnt);
	}
	return answer;
}