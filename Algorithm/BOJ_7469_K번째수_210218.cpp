#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, ans;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v.assign(N, { 0,0 });
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.first < b.first;
	});
	int s = 0, e = 0, o = 0, cnt = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e >> o; cnt = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (s <= v[j].second && v[j].second <= e)
			{
				ans = v[j].first;
				cnt++;
			}
			if (cnt == o)
			{
				cout << ans << "\n";
				break;
			}
		}
	}
	return 0;
}