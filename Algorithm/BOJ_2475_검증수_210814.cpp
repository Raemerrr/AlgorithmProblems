#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef unsigned long long ull;
const int arrSize = 5;
vector<ull> v;
ull answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	v.assign(arrSize, 0);
	for (int i = 0; i < arrSize; i++)
	{
		cin >> v[i];
		answer += pow(v[i], 2);
	}
	cout << (answer % 10) << "\n";
	return 0;
}