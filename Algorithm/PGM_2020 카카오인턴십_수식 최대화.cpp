#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//�ʱ� ���� ����
vector<int> nums;
//�ʱ� ���� ��ȣ ����
vector<char> op;
//�۾� ���� ��ȣ ����
vector<vector<int>> indexs;
vector<map<int, int>> operators;

long long Calc(const long long& a, const long long& b, const char c)
{
	if (c == '+')
	{
		return a + b;
	}
	else if (c == '-')
	{
		return a - b;
	}
	else// if (c == '*')
	{
		return a * b;
	}
}

//�� �����ڿ� ���� ������ �����Ѵ�.
void proc(const string & str)
{
	vector<vector<char>> order
	{
		{'+','-','*' },
		{'+','*','-' },
		{'*','+','-' },
		{'*','-','+' },
		{'-','*','+' },
		{'-','+','*' },
	};
	for (const auto& o : order)
	{
		vector<int> tempOrders;
		map<int, int> tempMap;
		for (const auto& d : o)
		{
			for (int i = 0; i < op.size(); i++)
			{
				if (op[i] == d)
				{
					tempMap[tempOrders.size()] = i;
					tempOrders.emplace_back(i);
				}
			}
		}
		indexs.push_back(tempOrders);
		operators.push_back(tempMap);
	}
}

//���ڿ� �����ڸ� ������ �Լ�
void subString(const string& str)
{
	string s;
	for (int i = 0; i < str.size(); i++)
	{
		char d = str[i];
		if (d != '+' && d != '-' && d != '*')
		{
			s += d;
			//������ ���ڶ��
			if (i == str.size() - 1)
			{
				nums.push_back(stoi(s));
				break;
			}
		}
		else
		{
			op.push_back(d);
			nums.push_back(stoi(s));
			s = "";
		}
	}
}

long long solution(string expression) {
	long long answer = -922337203685477580;
	subString(expression);
	proc(expression);
	for (int z = 0; z < indexs.size(); z++)
	{
		vector<long long> temp(nums.begin(), nums.end());
		for (int i = 0; i < indexs[z].size(); i++)
		{
			int idx = indexs[z][i];
			long long insertNum = Calc(temp[idx], temp[idx + 1], op[operators[z][i]]);
			temp.erase(temp.begin() + idx, temp.begin() + idx + 2);
			temp.insert(temp.begin() + idx, insertNum);
			for (int j = i + 1; j < indexs[z].size(); j++)
			{
				if (idx < indexs[z][j])
				{
					indexs[z][j]--;
				}
			}
		}
		if (temp[0] < 0)
		{
			temp[0] *= -1;
		}
		answer = (answer > temp[0]) ? answer : temp[0];
	}
	return answer;
}

int main()
{
	//"100-200*300-500+20"	60420
	//"50*6-3*2"	300
	string s = "50*6-3*2";
	cout << solution(s) << "\n";
	return 0;
}