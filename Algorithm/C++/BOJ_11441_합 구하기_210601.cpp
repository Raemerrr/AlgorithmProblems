#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> sum;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.assign(N, 0);
	sum.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		sum[i] = ((i > 0) ? v[i] + sum[i - 1] : v[i]);
	}
	cin >> M;
	for (int z = 0; z < M; z++)
	{
		int i = 0, j = 0; cin >> i >> j; i--, j--;
		if (i > 0)
		{
			if (j < N - 1)
			{
				cout << sum[N - 1] - sum[i - 1] - (sum[N - 1] - sum[j]) << "\n";
			}
			else
			{
				cout << sum[N - 1] - sum[i - 1] << "\n";
			}
		}
		else
		{
			cout << sum[j] << "\n";
		}
	}
	return 0;
}