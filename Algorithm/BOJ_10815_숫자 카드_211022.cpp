#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> v;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num = 0; cin >> num;
		auto it = lower_bound(v.begin(), v.end(), num);
		cout << ((it == v.end() || (*it) != num) ? "0" : "1") << " ";
	}
	cout << "\n";
	return 0;
}