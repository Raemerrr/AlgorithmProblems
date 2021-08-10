#include <iostream>

using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int num1 = 0, num2 = 0; cin >> num1 >> num2;
		cout << "Case #" << i << ": " << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
	}
	return 0;
}