#include <iostream>
#include <string>

using namespace std;

string str, pattern, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> str >> pattern;
	for (int i = 0; i < str.size(); i++)
	{
		answer += str[i];
		if (answer.size() >= pattern.size() && answer.back() == pattern.back()
			&& answer.substr(answer.size() - pattern.size(), pattern.size()) == pattern)
		{
			for (int j = 0; j < pattern.size(); j++)
			{
				answer.pop_back();
			}
		}
	}
	cout << ((answer.empty()) ? "FRULA" : answer) << "\n";
	return 0;
}