#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int N;
int ans;

void dfs(int days, int value)
{
	if (days == N)
	{
		ans = (ans > value) ? ans : value;
		return;
	}

	if (v[days].first + days <= N)
	{
		dfs(v[days].first + days, value + v[days].second);
	}
	if (days + 1 <= N)
	{
		dfs(days + 1, value);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	v = vector<pair<int, int>>(N, pair<int, int>(0, 0));
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	dfs(0, 0);
	cout << ans << "\n";
	return 0;
}