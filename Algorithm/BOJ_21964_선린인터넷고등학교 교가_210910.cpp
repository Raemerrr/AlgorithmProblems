#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N = 0; cin >> N;
	string str; cin >> str; 
	cout << str.substr(N - 5, 5) << "\n";;
	return 0;
}