#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> dp;

void Func()
{
	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	dp = vector<int>(N + 1, 0);
	Func();
	cout << dp[N] << "\n";
}