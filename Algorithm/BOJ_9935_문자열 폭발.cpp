#include <iostream>
#include <string>

using namespace std;

string str, pattern;

string Proc()
{
	string temp = "";
	for (int i = 0; i < str.size(); i++)
	{
		temp += str[i];
		//마지막으로 들어온 인덱스
		int curIndex = temp.size() - 1;
		if (temp[curIndex] == pattern[pattern.size() - 1])
		{
			//폭발 시키기 충분한 길이 인지
			if (temp.size() >= pattern.size())
			{
				//temp의 최근들어온 내용이 폭발 가능한 내용이라면
				if (temp.substr(curIndex - pattern.size() + 1) == pattern)
				{
					//문자열 폭발!!
					for (int j = 0; j < pattern.size(); j++)
					{
						temp.pop_back();
					}
				}
			}
		}
	}
	return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> str >> pattern;
	if (Proc().size() > 0)
	{
		cout << Proc() << "\n";
	}
	else
	{
		cout << "FRULA\n";
	}
	return 0;
}