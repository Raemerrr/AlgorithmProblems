#include <iostream>
#include <vector>

using namespace std;

const int INF = 10001;
int N, maxNum;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	v.assign(INF, 0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0; cin >> num;
		v[num]++;
		maxNum = (maxNum > num) ? maxNum : num;
	}
	for (int i = 1; i <= maxNum; i++)
	{
		for (int j = 0; j < v[i]; j++)
		{
			cout << i << "\n";
		}
	}
	return 0;
}