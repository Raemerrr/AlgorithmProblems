#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M, answer;
map<string, bool> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	while (N--)
	{
		string str; cin >> str;
		m[str] = true;
	}
	while (M--)
	{
		string str; cin >> str;
		if (m.count(str)) { answer++; }
	}
	cout << answer << "\n";
	return 0;
}