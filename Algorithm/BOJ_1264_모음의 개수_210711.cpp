#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkVowel(const char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		int answer = 0;
		string str;
		getline(cin, str);
		if (str == "#") break;
		for (const char d : str) { if (checkVowel((char)tolower(d))) { answer++; } }
		cout << answer << "\n";
	}
	return 0;
}