#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	const int INF = 987654321;
	int answer = INF;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	vector<vector<int>> node(n, vector<int>(n, 0));
	for (const vector<int>& d : fares) {
		//양방향 연결
		node[d[0] - 1][d[1] - 1] = d[2];
		node[d[1] - 1][d[0] - 1] = d[2];
	}
	//dp 초기화
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				dp[i][j] = (node[i][j] > 0) ? node[i][j] : INF;
			}
		}
	}
	//플로이드-와샬 : 각 지점 간 최단 거리 구하기 
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dp[i][k] != INF && dp[k][j] != INF)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
	}
	//시작 지점에서 A와 B로 가는 길이 있는 경우 : 각자 타고 가는 비용 구하기 (문제 특성 상.. 조건은 무의미..)
	answer = (dp[s - 1][b - 1] < INF && dp[s - 1][a - 1] < INF) ? dp[s - 1][b - 1] + dp[s - 1][a - 1] : INF;
	//시작 지점을 제외한 중간 지점까지 합승 후 각자 가는 비용 구하기
	for (int i = 0; i < n; i++)
	{
		//시작 지점 제외, 중간 지점까지 A와 B중 하나라도 갈 수 없다면 제외
		if (i == s - 1 || dp[s - 1][i] >= INF || dp[i][b - 1] >= INF || dp[i][a - 1] >= INF) continue;
		//시작 지점 -> 중간 지점(i)까지의 거리 + 중간 지점(i) -> B까지 + 중간 지점(i) -> A까지 비용 구하기
		answer = min((dp[s - 1][i] + dp[i][b - 1] + dp[i][a - 1]), answer);
	}
	return answer;
}

int main() {
	// case : 1
	//int n = 6, s = 4, a = 6, b = 2;
	//vector<vector<int>> fares{ {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} };
	// case : 2
	int n = 7, s = 3, a = 4, b = 1;
	vector<vector<int>> fares{ {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6} };
	cout << solution(n, s, a, b, fares) << "\n";
	return 0;
}