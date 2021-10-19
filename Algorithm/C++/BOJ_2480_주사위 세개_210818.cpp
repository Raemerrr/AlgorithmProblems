#include <iostream>
#include <map>

using namespace std;

int A, B, C, key, val, answer;
map<int, int, greater<int>> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> C;
	m[A]++, m[B]++, m[C]++;
	for (const pair<int, int>& d : m) {
		if (val < d.second)
		{
			val = d.second;
			key = d.first;
		}
	}
	switch (val)
	{
	case 1:
		answer = (*m.begin()).first * 100;
		break;
	case 2:
		answer = 1000 + key * 100;
		break;
	case 3:
		answer = 10000 + (*m.begin()).first * 1000;
		break;
	default:
		break;
	}
	cout << answer << "\n";
	return 0;
}