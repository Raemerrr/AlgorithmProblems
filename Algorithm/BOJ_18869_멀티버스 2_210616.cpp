#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer;
vector<vector<int>> v;

void indexing(vector<int>& arr) {
	vector<int> idx(arr.begin(), arr.end());
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	for (auto& d : arr) {
		d = (lower_bound(idx.begin(), idx.end(), d) - idx.begin());
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> v[i][j];

	for (int i = 0; i < N; i++) indexing(v[i]);

	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			answer += (v[i] == v[j]) ? 1 : 0;
	cout << answer << "\n";
	return 0;
}