#include <iostream>
#include <string>

using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	//16진수
	if (str.size() > 1 && str.substr(0, 2) == "0x")
	{
		cout << stoi(str, nullptr, 16) << "\n";
	}
	//8진수
	else if (!str.empty() && str[0] == '0')
	{
		cout << stoi(str, nullptr, 8) << "\n";
	}
	else
	{
		cout << str << "\n";
	}
	return 0;
}