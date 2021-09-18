#include <iostream>
#include <string>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		int num = 0; string str; cin >> num >> str;
		str.erase(str.begin() + (num - 1));
		cout << str << "\n";
	}
	return 0;
}