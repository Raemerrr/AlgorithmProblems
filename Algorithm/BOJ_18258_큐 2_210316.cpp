#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	cin.ignore();
	while (test_case--)
	{
		string str;
		getline(cin, str);
		if (str == "front")
		{
			cout << (q.empty() ? -1 : q.front()) << "\n";
		}
		else if (str == "back")
		{
			cout << (q.empty() ? -1 : q.back()) << "\n";
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << (q.empty() ? 1 : 0) << "\n";
		}
		else if (str == "pop")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else// if (str == "push")
		{
			q.push(stoi(string(str.begin() + 5, str.end())));
		}
	}
	return 0;
}