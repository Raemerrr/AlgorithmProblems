#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
map<string, bool, greater<string>> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		string person, status; cin >> person >> status;
		if (status == "enter")
		{
			m[person] = true;
		}
		else //if (status == "leave")
		{
			if (m.count(person))
			{
				m.erase(person);
			}
		}
	}
	for (const pair<string, bool>& d : m) { cout << d.first << "\n"; }
	return 0;
}