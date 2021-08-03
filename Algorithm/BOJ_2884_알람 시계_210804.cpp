#include <iostream>

using namespace std;

int hh, mm;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> hh >> mm;
	mm -= 45;
	if (mm < 0)
	{
		hh -= 1;
		mm = 60 + mm;
	}
	if (hh < 0)
	{
		hh = 24 + hh;
	}
	cout << hh << " " << mm << "\n";
	return 0;
}