#include <iostream>

using namespace std;

int N;

int factorial(const int n) {
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cout << factorial(N) << "\n";
	return 0;
}