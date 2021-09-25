#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) v.push_back(i);
	while (M--)
	{
		int idx1 = 0, idx2 = 0; cin >> idx1 >> idx2; idx1--;
		reverse(v.begin() + idx1, v.begin() + idx2);
	}
	for (const int d : v) cout << d << " ";
	cout << "\n";
	return 0;
}