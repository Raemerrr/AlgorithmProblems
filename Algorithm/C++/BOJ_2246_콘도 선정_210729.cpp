#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		int D = 0, C = 0; cin >> D >> C;
		v.emplace_back(D, C);
	}
	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first)
		{
			return a.second < b.second;
		}
		return a.first < b.first;
		});
	answer.push_back(v[0]);
	for (int i = 1; i < v.size(); i++)
	{
		pair<int, int> pii = answer.back();
		if (pii.first != v[i].first && v[i].second < pii.second)
		{
			answer.push_back(v[i]);
		}
	}
	cout << answer.size() << "\n";
	return 0;
}