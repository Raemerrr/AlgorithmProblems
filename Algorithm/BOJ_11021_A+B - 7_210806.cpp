#include <iostream>

using namespace std;

int T, A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> A >> B;
		cout << "Case #" << i << ": " << A + B << "\n";
	}
	return 0;
}