#include <iostream>
#include <map>

using namespace std;
typedef unsigned long long ull;

bool Proc()
{
	map<ull, bool> m;
	ull N = 0;
	cin >> N;
	m[N] = true;
	while (N > 1)
	{
		if (N % 2 == 0) { N = N / 2; }
		else { N = (3 * N) + 3; }
		if (m[N])
		{
			return true;
		}
		m[N] = true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 0;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		if (Proc())
		{
			cout << "#" << test_case << " NO\n";
		}
		else
		{
			cout << "#" << test_case << " YES\n";
		}
	}
	return 0;
}