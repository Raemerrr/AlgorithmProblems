#include <iostream>
#include <string>

using namespace std;

string str, pattern, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> str >> pattern;
	for (const char d : str) {
		answer += d;
		if (answer.size() >= pattern.size() && pattern.back() == d && answer.substr(answer.size() - pattern.size(), pattern.size()) == pattern) {
			for (int i = 0; i < pattern.size(); i++) answer.pop_back();
		}
	}
	cout << (answer.empty() ? "FRULA" : answer) << "\n";
	return 0;
}