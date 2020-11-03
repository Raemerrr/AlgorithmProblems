#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	vector<int> tempMin(3, 0);
	vector<int> tempMax(3, 0);
	vector<int> colMax(3, 0);
	vector<int> colMin(3, 0);
	for (int t = 0; t < N; t++)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> tempMax[i];
			tempMin[i] = tempMax[i];
			tempMax[i] += max(colMax[1], (i == 1) ? max(colMax[0], colMax[2]) : colMax[i]);
			tempMin[i] += min(colMin[1], (i == 1) ? min(colMin[0], colMin[2]) : colMin[i]);
		}
		colMax = tempMax;
		colMin = tempMin;
	}
	cout << *max_element(colMax.begin(), colMax.end()) << " " << *min_element(colMin.begin(), colMin.end()) << "\n";
	return 0;
}