#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		string str; cin >> str;
		int answer = 1;
		if (str == "0") break;
		for (const char d : str) {
			switch (d)
			{
			case '0' :
				answer += 4;
				break;
			case '1':
				answer += 2;
				break;
			default:
				answer += 3;
				break;
			}
			answer += 1;
		}
		cout << answer << "\n";
	}
	return 0;
}