#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool flag;
string str;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		getline(cin, str);

		//cin >> str;
		if (str == "������ ����� ��")
		{
			break;
		}
		else if (str == "������ ����� ����")
		{
			flag = true;
		}
		else if (flag)
		{
			if (str == "����")
			{
				v.push_back(str);
			}
			else
			{
				if (!v.empty())
				{
					v.pop_back();
				}
				else
				{
					v.push_back(str);
					v.push_back(str);
				}
			}
		}
	}
	cout << ((v.empty()) ? "�������� �����" : "����") << "\n";
	return 0;
}