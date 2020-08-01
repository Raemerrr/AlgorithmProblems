#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;
string str;
string temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//한 줄 입력
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) 
	{
		if (str[i] != ' ')
		{
			temp += str[i];
		}
		else
		{
			if (!temp.empty())
			{
				v.push_back(temp);
			}
			temp.clear();
		}
		if (i == str.size() - 1 && !temp.empty())
		{
			v.push_back(temp);
		}
	}
	cout << v.size() << "\n";
	return 0;
}