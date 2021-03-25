#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	while (test_case--)
	{
		string str;
		list<char> answer;
		cin >> str;
		auto it = answer.begin();
		for (const char c : str) {
			if (c == '<')
			{
				if (it != answer.begin())
				{
					--it;
				}
			}
			else if (c == '>')
			{
				if (it != answer.end())
				{
					++it;
				}
			}
			else if (c == '-')
			{
				if (it != answer.begin())
				{
					auto temp = it;
					answer.erase(--temp);
				}
			}
			else
			{
				answer.insert(it, c);
			}
		}
		cout << string(answer.begin(), answer.end()) << "\n";
	}
	return 0;
}