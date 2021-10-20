#include <iostream>
#include <string>

using namespace std;

int main() {
	string str; cin >> str;
	for (const char d : str) {
		string s = to_string((int)d);
		int length = 0;
		for (const char z : s) length += z - '0';
		for (int i = 0; i < length; i++) cout << d;
		cout << "\n";
	}
	return 0;
}