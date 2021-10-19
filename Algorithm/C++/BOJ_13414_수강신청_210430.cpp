#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M;
map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		string num = ""; cin >> num;
		m[num] = i;
	}
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
		return a.second < b.second;
		});
	int loop = (v.size() < N) ? v.size() : N;
	for (int i = 0; i < loop; i++) {
		cout << v[i].first << "\n";
	}
	return 0;
}