#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> getPi(const string& str)
{
	vector<int> pi(str.size(), 0);
	int j = 0;
	for (int i = 1; i < str.size(); i++)
	{
		while (j > 0 && str[i] != str[j])
		{
			j = pi[j - 1];
		}
		if (str[i] == str[j])
		{
			pi[i] = ++j;
		}
	}
	return pi;
}

int KMP(const string& str, const string& pattern)
{
	int ans = 0;
	int j = 0;
	vector<int> pi = getPi(pattern);
	for (int i = 0; i < str.size(); i++)
	{
		while (j > 0 && str[i] != pattern[j])
		{
			j = pi[j - 1];
		}
		if (str[i] == pattern[j])
		{
			if (j == pattern.size() - 1)
			{
				ans++;
				j = pi[j];
			}
			else
			{
				j++;
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		string pattern, str;
		cin >> pattern >> str;
		cout << KMP(str, pattern) << "\n";
	}
	return 0;
}