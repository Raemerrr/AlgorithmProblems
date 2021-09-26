#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		vector<int> v(3, 0); cin >> v[0] >> v[1] >> v[2];
		sort(v.begin(), v.end());
		if (v[0] == 0 && v[1] == 0 && v[2] == 0)
			break;

		if (v[0] == v[1] && v[1] == v[2])
			cout << "Equilateral\n";
		else if ((v[0] + v[1]) <= v[2])
			cout << "Invalid\n";
		else if (v[0] == v[1] || v[0] == v[1] || v[1] == v[2])
			cout << "Isosceles\n";
		else// if (v[0] != v[1] && v[0] != v[2] && v[1] != v[2])
			cout << "Scalene\n";
	}
	return 0;
}