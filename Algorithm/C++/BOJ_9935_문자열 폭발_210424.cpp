#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string str, pattern, answer;
	cin >> str >> pattern;
	for (const auto& d : str) {
		answer += d;
		if (answer.size() >= pattern.size() && d == pattern[pattern.size() - 1] && answer.substr(answer.size() - pattern.size(), pattern.size()) == pattern) {
			for (int i = 0; i < pattern.size(); i++) {
				answer.pop_back();
			}
		}
	}
	cout << (answer.empty() ? "FRULA" : answer) << "\n";
	return 0;
}