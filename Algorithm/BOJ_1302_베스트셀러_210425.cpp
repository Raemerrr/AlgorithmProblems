#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int N;
map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		string str; cin >> str;
		m[str]++;
	}
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
		if (a.second == b.second)
		{
			return a.first < b.first;
		}
		return a.second > b.second;
	});
	cout << v[0].first << "\n";
	return 0;
}