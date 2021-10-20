#include <iostream>
#include <vector>

using namespace std;

int N, answer, add;
vector<int> v;
bool flag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	for (const int d : v) {
		if (d == 0)
		{
			add = 0;
			flag = false;
		}
		else //if (d == 1)
		{
			add = ((flag) ? add + 1 : 1);
			flag = true;
		}
		answer += add;
	}
	cout << answer << "\n";
	return 0;
}