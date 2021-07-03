#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int num = 30;
vector<bool> v;
vector<int> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	v.assign(num, false);
	for (int i = 0; i < num - 2; i++)
	{
		int idx = 0; cin >> idx; idx--;
		v[idx] = true;
	}
	for (int i = 0; i < num; i++)
	{
		if (!v[i]) { cout << i + 1 << "\n"; }
	}
	return 0;
}