#include <iostream>
#include <vector>

using namespace std;
int n, k;
vector<int> v;
vector<int> dp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	v = vector<int>(n, 0);
	dp = vector<int>(k + 1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	//���� ������ ���� �ʴ� ��� + 1
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = v[i]; j <= k; j++)
		{
			dp[j] += dp[j - v[i]];
		}
	}
	cout << dp[k] << "\n";
	return 0;
}