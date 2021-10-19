#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 3; i++)
	{
		int h1 = 0, m1 = 0, s1 = 0, h2 = 0, m2 = 0, s2 = 0;
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
		int total = ((h2 * 3600) + (m2 * 60) + s2) - ((h1 * 3600) + (m1 * 60) + s1);
		cout << total / 3600 << " ";
		total %= 3600;
		cout << total / 60 << " ";
		cout << total % 60 << "\n";
	}
	return 0;
}