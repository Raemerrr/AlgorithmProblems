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
	//패턴 문자열이 나타나는 위치
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
			//패턴과 매칭
			if (j == pattern.size() - 1)
			{
				j = pi[j];
				//+ 2의 이유 : index + 1, 문자열 길이 + 1 
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