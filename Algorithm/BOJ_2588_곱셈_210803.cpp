#include <iostream>
#include <string>

using namespace std;

int num;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> num >> str;
	cout << (num * (str[2] - '0')) << "\n";
	cout << (num * (str[1] - '0')) << "\n";
	cout << (num * (str[0] - '0')) << "\n";
	cout << (num * stoi(str)) << "\n";
	return 0;
}