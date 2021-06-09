#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;
int N, K;
vector<LL> sum;
LL answer;
map<LL, LL> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	sum.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		int num = 0; cin >> num;
		sum[i] = (i == 0) ? num : sum[i - 1] + num;
	}
	for (int i = 0; i < N; i++)
	{
		// i까지 부분합이 K일 때
		if (sum[i] == K) answer++;
		// i까지 부분합 - K인 값이 이전에 존재했었다면 answer에 더한다.
		answer += (m.count(sum[i] - K)) ? m[sum[i] - K] : 0;
		// i까지 부분합을 map에 저장한다.
		m[sum[i]]++;
	}
	cout << answer << "\n";
	return 0;
}