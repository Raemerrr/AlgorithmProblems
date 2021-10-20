#include <iostream>
#include <string>

using namespace std;

int ans;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	cin.ignore();
	while (test_case--)
	{
		ans = 0;
		getline(cin, str);
		while (!str.empty())
		{
			string tempStr;
			while (true)
			{
				if (str.empty())
				{
					break;
				}
				char front = str[0];
				str.erase(str.begin());
				if (isalnum(front))
				{
					tempStr += front;
				}
				else
				{
					break;
				}
			}
			if (!tempStr.empty())
			{
				ans += stoi(tempStr);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}