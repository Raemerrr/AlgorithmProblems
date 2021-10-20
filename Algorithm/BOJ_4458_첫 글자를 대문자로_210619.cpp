#include <iostream>
#include <string>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		string str;
		getline(cin, str);
		str[0] = toupper(str[0]);
		cout << str << "\n";
	}
	return 0;
}