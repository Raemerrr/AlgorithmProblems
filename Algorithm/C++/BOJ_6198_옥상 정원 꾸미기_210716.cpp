#include <iostream>
#include <vector>	
#include <algorithm>

using namespace std;

int N, answer;
vector<int> v, store;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < N; i++) {
		while (!store.empty() && store.back() <= v[i])
		{
			store.pop_back();
		}
		store.push_back(v[i]);
		answer += store.size() - 1;
	}
	cout << answer << "\n";
	return 0;
}