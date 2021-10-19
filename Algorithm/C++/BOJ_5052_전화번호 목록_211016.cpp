#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T, N;
map<char, vector<string>> m;

bool proc() {
	for (pair<char, vector<string>> d : m) {
		sort(d.second.begin(), d.second.end());
		for (int i = 0; i < d.second.size() - 1; i++)
		{
			for (int j = i + 1; j < d.second.size(); j++)
			{
				// 최적화를 더 한다면 추가 d.second[i].size() < d.second[j].size()
				if (d.second[i] == d.second[j].substr(0, d.second[i].size()))
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		m.clear();
		cin >> N;
		while (N--)
		{
			string str; cin >> str;
			m[str[0]].emplace_back(str);
		}
		cout << ((proc()) ? "YES" : "NO") << "\n";
	}
	return 0;
}