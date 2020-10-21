#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> temp;
	for (int i = 0; i < progresses.size(); i++)
	{
		//�̸� �Ϸ� ���ڸ� ����Ѵ�.
		temp.push_back(static_cast<int>(ceil((100.0f - progresses[i]) / speeds[i])));
	}
	//���� ù ��° ������ �����Ѵ�.
	int num = temp[0];
	while (!temp.empty())
	{
		int cnt = 0;
		while (!temp.empty() && num >= temp[0])
		{
			temp.erase(temp.begin());
			cnt++;
		}
		//���� ���� ū ���� 0�� �ε����� �ִ� ���̴�.
		if (!temp.empty()) { num = temp[0]; }
		answer.emplace_back(cnt);
	}
	return answer;
}