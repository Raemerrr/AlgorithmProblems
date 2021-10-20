#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		vector<int> v(3, 0);
		cin >> v[0] >> v[1] >> v[2];
		if (v[0] == 0 && v[1] == 0 && v[2] == 0)
		{
			break;
		}
		sort(v.begin(), v.end());
		if ((int)pow(v[2], 2) == (int)(pow(v[0], 2) + pow(v[1], 2)))
		{
			cout << "right\n";
		}
		else
		{
			cout << "wrong\n";
		}
	}
	return 0;
}
