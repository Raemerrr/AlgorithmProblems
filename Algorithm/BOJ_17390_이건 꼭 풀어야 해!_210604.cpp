#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
int N, Q;
vector<int> v;
vector<LL> sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	v.assign(N, 0);
	sum.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
	{
		sum[i] = ((i > 0) ? sum[i - 1] + v[i] : v[i]);
	}
	while (Q--)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2; num1--, num2--;
		LL diffSum = ((num1 - 1 < 0) ? 0 : sum[num1 - 1]);
		cout << (sum[num2] - diffSum) << "\n";
	}
	return 0;
}