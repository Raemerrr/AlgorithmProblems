#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans, sum;
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
	sort(v.begin(), v.end());
	for (const auto& data : v)
	{
		sum += data;
		ans += sum;
	}
	cout << ans << "\n";
	return 0;
}