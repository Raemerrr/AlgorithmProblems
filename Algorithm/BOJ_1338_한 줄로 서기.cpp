#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;
vector<int> ans;

void Greedy()
{
	ans = vector<int>(N, -1);
	while (!v.empty())
	{
		pair<int, int> cur = v[v.size() - 1];
		v.pop_back();
		int cnt = 0;
		for (int i = 0; i < ans.size(); i++)
		{
			if (ans[i] == -1)
			{
				if (cnt == cur.second)
				{
					ans[i] = cur.first;
					break;
				}
				cnt++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<pair<int, int>>(N, pair<int, int>(0, 0));
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].second;
		v[i].first = i + 1;
	}
	sort(v.rbegin(), v.rend());
	Greedy();
	for (const auto& d : ans) { cout << d << " "; }cout << "\n";
	return 0;
}