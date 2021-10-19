#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, Start = 1;
vector<vector<int>> v;
vector<bool> visited;
vector<vector<int>> dp;

//v�� ���� ������ �ܹ��� ����� ����
void bfs() {
	vector<vector<int>> og = v;
	v.assign(N + 1, vector<int>());
	queue<int> q;
	q.push(Start);
	visited[Start] = true;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		for (const auto& d : og[front]) {
			if (!visited[d]) {
				visited[front] = true;
				q.push(d);
				v[front].push_back(d);
			}
		}
	}
}

int solution(int cur, bool flag) {
	//���� ����
	if (dp[cur][flag] != -1)
	{
		return dp[cur][flag];
	}
	//���� �� �ƴ���(early adaptor)��� �ֺ��� �� �ƴ���(early adaptor)�̰ų� �ƴϰų� ��� ����.
	if (flag)
	{
		dp[cur][flag] = 1;
		for (const auto& Next : v[cur])
		{
			dp[cur][flag] += min(solution(Next, true), solution(Next, false));
		}
	}
	//���� �� �ƴ���(early adaptor)�� �ƴ϶�� �ֺ��� ������ �� �ƴ���(early adaptor)������.
	else
	{
		dp[cur][flag] = 0;
		for (const auto& Next : v[cur])
		{
			dp[cur][flag] += solution(Next, true);
		}
	}
	return dp[cur][flag];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.assign(N + 1, vector<int>());
	visited.assign(N + 1, false);
	dp.assign(N + 1, vector<int>(2, -1));
	int a = 0, b = 0;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		//����� ����
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	cout << min(solution(Start, true), solution(Start, false)) << "\n";
	return 0;
}