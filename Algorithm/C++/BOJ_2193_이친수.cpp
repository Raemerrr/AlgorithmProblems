#include <iostream>
#include <vector>

using namespace std;

int N;
vector<unsigned long long> dp;

void Func()
{
	dp[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	dp = vector<unsigned long long>(N + 1, 0);
	Func();
	cout << dp[N] << "\n";
	return 0;
}