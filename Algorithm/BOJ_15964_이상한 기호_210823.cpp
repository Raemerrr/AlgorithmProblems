#include <iostream>

using namespace std;

long long A, B, answer;

int main() {
	cin >> A >> B;
	answer = (A + B) * (A - B);
	cout << answer << "\n";
	return 0;
}