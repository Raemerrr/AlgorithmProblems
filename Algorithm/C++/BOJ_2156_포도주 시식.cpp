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
	//마지막 잔을 마셨는지의 판단은 마지막잔 + 2거리까지 봐야하기 때문
	for (int i = 3; i <= N + 2; i++)
	{
		dp[i] = max(dp[i - 2], dp[i - 3] + v[i - 1]) + v[i];
		//여기서 끝난다면 100, 400, 2, 1, 4, 200 - 701이 나온다.
		//정답은 704 - 2잔 연속 안먹은 경우도 존재
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