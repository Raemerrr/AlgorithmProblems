/*
2가지만 염두하면 된다.

1. dp[i-1] > 0
  - 이전의 합이 음수라면 선택할 필요 없이 현재부터 다시 선택해나가면 된다.

  2. dp[i] + dp[i-1] > 0
  - 이전의 합과 현재의 수를 더한 값이 음수라면 선택할 필요가 없다.

6
-5 1 2 3 -4 5
correct answer: 7
*/
#include <iostream>
#include <vector>

using namespace std;
int N, ans;
vector<int> v;

void Proc()
{
	vector<int> dp(N, 0);
	dp[0] = v[0];
	//ans = 0으로 하면 음수의 최대값을 구할 수 없다.
	ans = dp[0];
	for (int i = 1; i < N; i++)
	{
		//굳이 더해서 득이 없음...
		if (dp[i - 1] < 0)
		{
			//현재부터 다시 선택
			dp[i] = v[i];
		}
		else
		{
			//더해서 양수라면
			if (dp[i - 1] + v[i] > 0)
			{
				dp[i] = dp[i - 1] + v[i];
			}
			//더해서 음수라면 다음 계산에서 영향을 주지 않으려면 0 넣기 사실 없어도 무방
			//이미 0으로 초기화 했기 때문
			//else
			//{
			//	dp[i] = 0;
			//}
		}
		ans = (ans > dp[i]) ? ans : dp[i];
	}
}

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
	Proc();
	cout << ans << "\n";
	return 0;
}