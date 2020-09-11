#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, dist, ans;
vector<int> v;
map<int, bool> m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> dist;
	v = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		m[v[i]] = false;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (!m[v[i]])
		{
			for (int j = v[i]; j < v[i] + dist; j++)
			{
				m[j] = true;
			}
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}