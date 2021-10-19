#include <iostream>
#include <string>
#include <map>

using namespace std;

string str;
map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	for (int size = 1; size <= str.size(); size++)
	{
		for (int i = 0; i < str.size() - (size - 1); i++)
		{
			m[str.substr(i, size)]++;
		}
	}
	cout << m.size() << "\n";
	return 0;
}