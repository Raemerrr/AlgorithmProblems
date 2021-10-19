#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> map;
vector<int> dp;

void Proc()
{
	//1~3 계단까지 최댓값 넣기
	dp[1] = map[1];
	dp[2] = max(map[2], map[1] + map[2]);
	dp[3] = max(map[1] + map[3], map[2] + map[3]);
	//전전칸까지의 최댓값 : dp[i - 2]
	//전전전칸까지의 최댓값과 전전칸의 값 : dp[i - 3] + map[i - 1]
	for (int i = 4; i <= N; i++)
	{
		dp[i] = max(dp[i - 2], dp[i - 3] + map[i - 1]) + map[i];
	}
	cout << dp[N] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	map = vector<int>(N + 1, 0);
	dp = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> map[i];
	}
	Proc();
	return 0;
}