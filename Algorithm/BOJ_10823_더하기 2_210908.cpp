#include <iostream>
#include <string>
#include <sstream>

using namespace std;

long long answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string str;
	string temp;
	while (getline(cin, temp)) str += temp;
	istringstream ss(str);
	string stringBuffer;
	while (getline(ss, stringBuffer, ','))
	{
		answer = ((stringBuffer != "") ? answer + stoi(stringBuffer) : answer);
	}
	cout << answer << "\n";
	return 0;
}