#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	for (int i = v.size() - 1; i > 0; i--)
	{
		while (v[i - 1] >= v[i])
		{
			v[i - 1]--;
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}