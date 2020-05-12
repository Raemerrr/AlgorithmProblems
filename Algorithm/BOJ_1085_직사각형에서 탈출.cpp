#include <iostream>

using namespace std;

int x, y, w, h;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> x >> y >> w >> h;
	int tempX = (x < (w - x)) ? x : (w - x);
	int tempY = (y < (h - y)) ? y : (h - y);
	int ans = (tempX < tempY) ? tempX : tempY;
	cout << ans << "\n";
	return 0;
}