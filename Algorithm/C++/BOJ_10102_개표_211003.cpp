#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<char, int> m;
	cin >> N >> str;
	for (const char d : str) m[d]++;
	cout << ((m['A'] == m['B']) ? "Tie" : ((m['A'] > m['B']) ? "A" : "B")) << "\n";
	return 0;
}