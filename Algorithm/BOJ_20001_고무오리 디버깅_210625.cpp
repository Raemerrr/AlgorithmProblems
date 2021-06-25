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
		if (str == "고무오리 디버깅 끝")
		{
			break;
		}
		else if (str == "고무오리 디버깅 시작")
		{
			flag = true;
		}
		else if (flag)
		{
			if (str == "문제")
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
	cout << ((v.empty()) ? "고무오리야 사랑해" : "힝구") << "\n";
	return 0;
}