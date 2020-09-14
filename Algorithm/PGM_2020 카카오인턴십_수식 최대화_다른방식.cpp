#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> nums;
vector<char> op;
vector<vector<int>> indexs;
vector<map<int, int>> operators;
vector<int> temp;
vector<bool> visited;


void DFS()
{
	if (temp.size() == op.size())
	{
		map<int, int> tempMap;
		for (int i = 0; i < temp.size(); i++)
		{
			tempMap[i] = temp[i];
		}
		operators.push_back(tempMap);
		indexs.push_back(temp);
	}
	else
	{
		for (int i = 0; i < op.size(); i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				temp.push_back(i);
				DFS();
				visited[i] = false;
				temp.pop_back();
			}
		}
	}
}

int Calc(const int a, const int b, const char c)
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

long long solution(string expression) {
	long long answer = -2147483646;
	string s;
	for (int i = 0; i < expression.size(); i++)
	{
		char d = expression[i];
		if (d != '+' && d != '-' && d != '*')
		{
			s += d;
			//마지막 글자라면
			if (i == expression.size() - 1)
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
	visited = vector<bool>(op.size(), false);
	DFS();
	//for (auto d : nums) { cout << d << "\n"; }
	//for (auto d : op) { cout << d << "\n"; }
	for (int z = 0; z < indexs.size(); z++)
	{
		vector<int> temp = nums;
		for (int i = 0; i < indexs[z].size(); i++)
		{
			int idx = indexs[z][i];
			int insertNum = Calc(temp[idx], temp[idx + 1], op[operators[z][i]]);
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
			temp[0] = temp[0] * -1;
		}
		answer = (answer > temp[0]) ? answer : temp[0];
	}
	return answer;
}

int main()
{
	//"100-200*300-500+20"	60420
	//"50*6-3*2"	300
	//string s = "100-200*300-500+20";
	//string s = "50*6-3*2";
	string s = "8*3+5+2";
	cout << solution(s) << "\n";
	/*vector<int>v{ 10,20,5,2 };
	for (auto d : v) { cout << d << " "; }cout << "\n";
	v.erase(v.begin() + 1, v.begin() + 3);
	for (auto d : v) { cout << d << " "; }cout << "\n";
	v.insert(v.begin() + 1, 100);
	for (auto d : v) { cout << d << " "; }cout << "\n";*/
	return 0;
}