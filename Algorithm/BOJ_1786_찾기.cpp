#include <iostream>
#include <vector>
#include <string>

using namespace std;

string T, P;

vector<int> getPi(const string& pattern)
{
	vector<int> pi(pattern.size(), 0);
	for (int i = 1, j = 0; i < pattern.size(); i++)
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

vector<int> KMP(const string& str, const string& pattern)
{
	//���� ���ڿ��� ��Ÿ���� ��ġ
	vector<int> pos;
	vector<int> pi = getPi(pattern);
	for (int i = 0, j = 0; i < str.size(); i++)
	{
		while (j > 0 && str[i] != pattern[j])
		{
			j = pi[j - 1];
		}
		if (str[i] == pattern[j])
		{
			//���ϰ� ��Ī
			if (j == pattern.size() - 1)
			{
				j = pi[j];
				//+ 2�� ���� : index + 1, ���ڿ� ���� + 1 
				pos.emplace_back(i - pattern.size() + 2);
			}
			else
			{
				++j;
			}
		}
	}
	return pos;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	getline(cin, T);
	getline(cin, P);
	vector<int> ans = KMP(T, P);
	cout << ans.size() << "\n";
	for (const auto& d : ans) { cout << d << " "; }cout << "\n";
	return 0;
}