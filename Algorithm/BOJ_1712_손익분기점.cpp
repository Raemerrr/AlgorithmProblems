#include <iostream>

using namespace std;
unsigned long long A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> C;
	if (B >= C) { cout << "-1\n"; return 0; }
	//½Ä Áß¿ä!
	cout << (A / (C - B)) + 1 << "\n";
	return 0;
}