#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;  cin >> T;
	while (T--)
	{
		int N = 0, total = 0; cin >> N;
		vector<vector<int>> sum(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++)
		{
			int num = 0; cin >> num;
			total += num;
			for (int j = 0; j <= i; j++)
			{
				sum[j][i] = ((i > 0) ? sum[j][i - 1] + num : num);
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = i; j < N; j++)
			{
				total = max(total, sum[i][j]);
			}
		}
		cout << total << "\n";
	}
	return 0;
}