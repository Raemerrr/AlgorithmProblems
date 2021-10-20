#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str1, str2, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> str1 >> str2;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	answer = to_string(stoi(str1) + stoi(str2));
	reverse(answer.begin(), answer.end());
	cout << stoi(answer) << "\n";
	return 0;
}