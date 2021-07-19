#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;
string str;
int maxLen;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (getline(cin, str))
	{
		v.push_back(str);
		maxLen = (str.size() > maxLen) ? str.size() : maxLen;
	}
	for (int i = 0; i < maxLen; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j].size() - 1 >= i)
			{
				cout << v[j][i];
			}
		}
	}
	cout << "\n";
	return 0;
}