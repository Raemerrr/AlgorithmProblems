#include <iostream>
#include <string>

using namespace std;

int N;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		cin >> str;
		cout << str.front() << str.back() << "\n";
	}
	return 0;
}