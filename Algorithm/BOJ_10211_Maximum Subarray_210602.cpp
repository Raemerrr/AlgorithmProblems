#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (0 < N)
	{
		cin >> M;
		int total = 0;
		vector<vector<int>> sum(M, vector<int>(M, 0));
		for (int z = 0; z < M; z++)
		{
			int num = 0;
			cin >> num;
			total += num;
			for (int i = 0; i <= z; i++)
			{
				sum[i][z] = ((z > 0) ? sum[i][z - 1] + num : num);
			}
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = i; j < M; j++)
			{
				total = max(total, sum[i][j]);
			}
		}
		cout << total << "\n";
		N--;
	}
	return 0;
}