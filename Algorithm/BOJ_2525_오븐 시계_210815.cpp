#include <iostream>

using namespace std;

int A, B, C;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> C;
	B += C;
	if (B >= 60)
	{
		A += (B / 60);
		if (A >= 24)
		{
			A %= 24;
		}
		B %= 60;
	}
	cout << A << " " << B << "\n";
	return 0;
}