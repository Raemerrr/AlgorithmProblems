#include <iostream>
#include <string>

using namespace std;

int main() {
	string str; cin >> str;
	for (const char c : str) {
		cout << ((isupper(c)) ? (char)tolower(c) : (char)toupper(c));
	}
	return 0;
}