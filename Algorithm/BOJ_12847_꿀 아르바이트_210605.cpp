#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

LL sum, answer;
int n, m;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	v.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < m; i++)
	{
		sum += v[i];
	}
	int s = 0, e = m;
	answer = sum;
	while (e < n)
	{
		sum -= v[s];
		sum += v[e];
		answer = max(sum, answer);
		s++, e++;
	}
	cout << answer << "\n";
	return 0;
}