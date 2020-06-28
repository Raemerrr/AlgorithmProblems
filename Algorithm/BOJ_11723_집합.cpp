#include <iostream>
#include <string>
#include <map>

using namespace std;

int M, num;
string str;
map<int, bool> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (str != "all" && str != "empty")
		{
			cin >> num;
		}
		if (str == "add")
		{
			m[num] = true;
		}
		else if (str == "remove")
		{
			m[num] = false;
		}
		else if (str == "check")
		{
			cout << m[num] << "\n";
		}
		else if (str == "toggle")
		{
			m[num] = !m[num];
		}
		else if (str == "all")
		{
			for (int j = 1; j <= 20; j++) { m[j] = true; }
		}
		else if (str == "empty")
		{
			for (int j = 1; j <= 20; j++) { m[j] = false; }
		}
	}
	return 0;
}