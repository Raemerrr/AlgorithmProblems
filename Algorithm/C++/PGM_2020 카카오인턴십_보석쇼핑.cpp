#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
	//���� �� ��ġ�� ����ϴ� ����
	map<string, vector<int>> m;
	//���� �� ������ ���� ��ġ
	vector<int> temp;
	set<string> s(gems.begin(), gems.end());
	//�������� �ߺ��� ������ ��
	int total = s.size();
	int cnt = 0;
	//�־��� ���� �� ���� ������ Ŭ �� ����. (�ʱ� �� = �ִ� ��)
	int len = gems.size();
	vector<pair<int, pair<int, int>>> answer;
	//Loop �� �� ª�� ������ ���� �� �ִ�.
	for (int i = 0; i < gems.size(); i++)
	{
		//������ ���Դ� ������ �ƴ϶�� ī��Ʈ
		if (m[gems[i]].empty())
		{
			cnt++;
		}
		//�Ź� �湮�ϴ� ���� ���� ���� ��ġ ���
		m[gems[i]].push_back(i + 1);
		//������ �ϼ� �Ǿ��ٸ�
		if (cnt == total)
		{
			//������ ���� ��ġ���� �� ���� ��� ������ �߸���.
			for (const auto& d : m)
			{
				temp.push_back(d.second[d.second.size() - 1]);
			}
			sort(temp.begin(), temp.end());
			int _start = temp[0];
			int _end = temp[temp.size() - 1];
			int tLen = _end - _start + 1;
			len = len < tLen ? len : tLen;
			//�ʱ�ȭ
			m.clear();
			temp.clear();
			cnt = 0;
			//�� ª�� ������ ã�� ����
			i = _start - 1;
			answer.emplace_back(len, make_pair(_start, _end));
		}
	}
	//���� ª�� ���� �� _start�� ���� ������ ������ �����ϱ� ���� ����
	sort(answer.begin(), answer.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
	{
		//������ ���̰� ���ٸ� ���� _start ������ ����
		if (a.first == b.first)
		{
			return a.second.first < b.second.first;
		}
		//������ ���̰� �ٸ��ٸ� ������ ���� ������ ����
		else
		{
			return a.first < b.first;
		}
	});
	return vector<int>{answer[0].second.first, answer[0].second.second};
}

/*
���α׷��ӽ� ����Ʈ�� main()�Լ��� �Է¹��� �ʽ��ϴ�.
������ ���� �ϱ� ���� �Է��س��� ���Դϴ�.
*/
int main()
{
	/*
	["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]	[3, 7]
	["AA", "AB", "AC", "AA", "AC"]	[1, 3]
	["XYZ", "XYZ", "XYZ"]	[1, 1]
	["ZZZ", "YYY", "NNNN", "YYY", "BBB"]	[1, 5]
	*/
	vector<string> v{ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
	//vector<string> v{ "AA", "AB", "AC", "AA", "AC" };
	//vector<string> v{ "XYZ", "XYZ", "XYZ" };
	//vector<string> v{ "ZZZ", "YYY", "NNNN", "YYY", "BBB" };
	cout << "[";
	for (const auto& d : solution(v))
	{
		cout << d << ":";
	}
	cout << "]\n";
	return 0;
}