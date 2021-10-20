#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int num = 5;
vector<vector<int>> v;
pair<int, int> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	v.assign(num, vector<int>(num, 0));
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1; j++)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < num; i++)
	{
		int tempScore = 0;
		for (int j = 0; j < num - 1; j++)
		{
			tempScore += v[i][j];
		}
		if (answer.second < tempScore)
		{
			answer.first = i + 1;
			answer.second = tempScore;
		}
	}
	cout << answer.first << " " << answer.second << "\n";
	return 0;
}