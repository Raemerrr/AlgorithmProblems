#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//초기 숫자 순서
vector<int> nums;
//초기 연산 기호 순서
vector<char> op;
//작업 예정 기호 순서
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

//각 연산자에 대한 순서를 저장한다.
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

//숫자와 연산자를 나누는 함수
void subString(const string& str)
{
	string s;
	for (int i = 0; i < str.size(); i++)
	{
		char d = str[i];
		if (d != '+' && d != '-' && d != '*')
		{
			s += d;
			//마지막 글자라면
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