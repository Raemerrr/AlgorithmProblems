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
		//���������� ���� �ε���
		int curIndex = temp.size() - 1;
		if (temp[curIndex] == pattern[pattern.size() - 1])
		{
			//���� ��Ű�� ����� ���� ����
			if (temp.size() >= pattern.size())
			{
				//temp�� �ֱٵ��� ������ ���� ������ �����̶��
				if (temp.substr(curIndex - pattern.size() + 1) == pattern)
				{
					//���ڿ� ����!!
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