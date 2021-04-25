#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0; cin >> test_case;
	while (test_case--)
	{
		int N = 0, answer = 1;
		map<string, set<string>> m;
		cin >> N;
		while (N--)
		{
			string str1, str2; cin >> str1 >> str2;
			m[str2].insert(str1);
		}
		if (m.size() == 1)
		{
			answer = (*m.begin()).second.size();
		}
		else
		{
			for (const pair<string, set<string>>& d : m) {
				answer *= (d.second.size() + 1);
			}
			answer--;
		}
		cout << answer << "\n";
	}
	return 0;
}