#include <iostream>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cout << ((N % 4 == 0 && (N % 400 == 0 || N % 100 != 0)) ? "1" : "0" ) <<"\n";
	return 0;
}