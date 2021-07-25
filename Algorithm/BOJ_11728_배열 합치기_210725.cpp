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
	v.assign(N + M, 0);
	for (int i = 0; i < N + M; i++) cin >> v[i];
	sort(v.begin(),v.end());
	for (const int d : v) { cout << d << " "; }cout << "\n";
	return 0;
}