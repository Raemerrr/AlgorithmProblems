#include <iostream>
#include <vector>

using namespace std;

const int MAX = 5;
vector<int> v;
int num = 101;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	v.assign(MAX, 0);
	for (int i = 0; i < MAX; i++) {
		cin >> v[i];
		num = ((v[i] < num) ? v[i] : num);
	}
	while (true)
	{
		int cnt = 0;
		for (int i = 0; i < MAX; i++)
		{
			cnt += ((num % v[i] == 0) ? 1 : 0);
		}
		if (cnt >= 3) break;
		num++;
	}
	cout << num << "\n";
	return 0;
}