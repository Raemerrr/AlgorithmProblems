#include <iostream>
#include <vector>
#include <map>

using namespace std;

int c = 100, s = 100, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--)
	{
		int cNum = 0, sNum = 0; cin >> cNum >> sNum;
		if (cNum != sNum)
		{
			if (cNum < sNum) c -= sNum;
			else s -= cNum;
		}
	}
	cout << c << "\n" << s << "\n";
	return 0;
}