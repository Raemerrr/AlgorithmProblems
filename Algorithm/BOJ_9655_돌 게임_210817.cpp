#include <iostream>

using namespace std;

int N;

int main() {
	cin >> N;
	cout << ((N % 2 == 0) ? "CY" : "SK") << "\n";
	return 0;
}