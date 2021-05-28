#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
int N, M, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> v[i][j];
		}
	}
	cin >> K;
	for (int z = 0; z < K; z++)
	{
		int i = 0, j = 0, x = 0, y = 0, answer = 0;
		cin >> i >> j >> x >> y; i--, j--, x--, y--;
		for (int a = i; a < x+1; a++)
		{
			for (int b = j; b < y+1; b++)
			{
				answer += v[a][b];
			}
		}
		cout << answer << "\n";
	}
	return 0;
}