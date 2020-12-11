#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str, pattern, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> str >> pattern;
	for (const auto& d : str) {
		answer += d;
		if (answer.size() >= pattern.size() && d == pattern[pattern.size() - 1])
		{
			if (pattern == string(answer.end() - pattern.size(), answer.end()))
			{
				for (int i = 0; i < pattern.size(); i++)
				{
					answer.pop_back();
				}
			}
		}
	}
	cout << ((answer.empty()) ? "FRULA" : answer) << "\n";
	return 0;
}