#include <iostream>
#include <vector>
#include <string>

using namespace std;
int len;
string str;

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
	cin >> len >> str;
	vector<int> pi = getPi(str);
	cout << len - pi[pi.size() - 1] << "\n";
	return 0;
}