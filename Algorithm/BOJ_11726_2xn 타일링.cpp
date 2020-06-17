#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> dp;

int Func(const int& num)
{
	if (num == 1) { return 1; }
	if (num == 2) { return 2; }
	if (dp[num] != 0) { return dp[num]; }
	return dp[num] = (Func(num - 1) + Func(num - 2)) % 10007;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	dp = vector<int>(N + 1, 0);
	cout << Func(N) << "\n";
	return 0;
}