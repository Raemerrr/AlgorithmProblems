#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		int answer = 0;
		map<char, int> m;
		string str; cin >> str;
		for (const char d : str) { m[d]++; }
		for (int i = 65; i <= 90; i++) {
			if (m[(char)i] == 0)
			{
				answer += i;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}