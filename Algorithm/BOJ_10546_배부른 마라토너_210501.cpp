#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str; cin >> str;
		m[str]++;
	}
	for (int i = 0; i < N - 1; i++)
	{
		string str; cin >> str;
		m[str]--;
		if (m[str] == 0)
		{
			m.erase(str);
		}
	}
	cout << (*m.begin()).first << "\n";
	return 0;
}