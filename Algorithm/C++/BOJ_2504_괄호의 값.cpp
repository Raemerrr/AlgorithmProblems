#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<char> s;

void Proc()
{
	long long answer = 0;
	int tempAns = 1;

	for (int i = 0; i < str.size(); i++)
	{
		//에러 체크
		if (s.empty() && (str[i] == ']' || str[i] == ')'))
		{
			answer = 0;
			break;
		}
		if (str[i] == '(' || str[i] == '[')
		{
			s.emplace(str[i]);
			if (str[i] == '(')
			{
				tempAns *= 2;
			}
			else // if (str[i] == '[')
			{
				tempAns *= 3;
			}
		}
		else if (str[i] == ')')
		{
			//에러 체크
			if (s.top() != '(')
			{
				break;
			}
			s.pop();
			if (str[i - 1] == '(')
			{
				answer += tempAns;
			}
			tempAns /= 2;
		}
		else // if (str[i] == ']')
		{
			//에러 체크
			if (s.top() != '[')
			{
				break;
			}
			s.pop();
			if (str[i - 1] == '[')
			{
				answer += tempAns;
			}
			tempAns /= 3;
		}
	}
	if (!s.empty())
	{
		cout << "0\n";
	}
	else
	{
		cout << answer << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	Proc();
	return 0;
}