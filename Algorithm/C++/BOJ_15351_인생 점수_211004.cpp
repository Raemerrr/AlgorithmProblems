#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> m;
int N;
void initMap() {
	m[' '] = 0;
	for (int i = 1; i <= 26; i++) m[(char)(i + 64)] = i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	initMap();
	cin >> N;
	cin.ignore();
	while (N--)
	{
		string str; getline(cin, str);
		int result = 0;
		for (char d : str) {
			result += m[d];
		}
		cout << ((result == 100) ? "PERFECT LIFE" : to_string(result)) << "\n";
	}
	return 0;
}
