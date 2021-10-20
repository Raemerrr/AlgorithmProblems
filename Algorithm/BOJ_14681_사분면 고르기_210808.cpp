#include <iostream>

using namespace std;

int y, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> x >> y;
	cout << ((x > 0 && y > 0) ? "1" : (x < 0 && y > 0) ? "2" : (x < 0 && y < 0) ? "3" : "4") << "\n";
	return 0;
}