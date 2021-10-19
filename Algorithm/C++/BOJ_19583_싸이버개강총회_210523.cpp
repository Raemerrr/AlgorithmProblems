#include <iostream>
#include <set>
#include <string>

using namespace std;

int S, E, Q, answer;
string sStr, eStr, qStr;
set<string> s;

int getTime(const string& str) {
	return (stoi(str.substr(0, 2)) * 60) + stoi(str.substr(3, 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> sStr >> eStr >> qStr;
	S = getTime(sStr);
	E = getTime(eStr);
	Q = getTime(qStr);
	string timeStr, name;
	while (cin >> timeStr >> name)
	{
		int time = getTime(timeStr);
		if (time <= S)
		{
			s.emplace(name);
		}
		else if (E <= time && time <= Q)
		{
			if (s.count(name))
			{
				answer++;
				s.erase(name);
			}
		}
	}
	cout << answer << "\n";
	return 0;
}