#include <iostream>
#include <string>
#include <map>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		string str1, str2;
		cin >> str1 >> str2;
		map<char, int> m;
		for (const char d : str1) {
			m[d]++;
		}
		for (const char d : str2) {
			m[d]--;
			if (m[d] == 0)
			{
				m.erase(d);
			}
		}
		cout << ((m.empty()) ? "Possible" : "Impossible") << "\n";
	}
	return 0;
}