#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, ans;
vector<int> dp;
vector<int> v;

void Func()
{
	dp[1] = v[1];
	dp[2] = max(v[1] + v[2], v[2]);
	//������ ���� ���̴����� �Ǵ��� �������� + 2�Ÿ����� �����ϱ� ����
	for (int i = 3; i <= N + 2; i++)
	{
		dp[i] = max(dp[i - 2], dp[i - 3] + v[i - 1]) + v[i];
		//���⼭ �����ٸ� 100, 400, 2, 1, 4, 200 - 701�� ���´�.
		//������ 704 - 2�� ���� �ȸ��� ��쵵 ����
		dp[i] = max(dp[i], dp[i - 1]);
		ans = max(ans, dp[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	dp = vector<int>(N + 3, 0);
	v = vector<int>(N + 3, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}
	Func();
	cout << ans << "\n";
	return 0;
}