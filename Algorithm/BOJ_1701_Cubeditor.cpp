#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str;
int ans;

vector<int> getPi(const string& pattern)
{
	int n = pattern.size();
	vector<int> pi(n, 0);
	for (int i = 1, j = 0; i < n; i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j])
		{
			pi[i] = ++j;
		}
	}
	return pi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		vector<int> pi = getPi(str.substr(i));
		for (const auto d : pi)
		{
			ans = (ans > d) ? ans : d;
		}
	}
	cout << ans << "\n";
	return 0;
}