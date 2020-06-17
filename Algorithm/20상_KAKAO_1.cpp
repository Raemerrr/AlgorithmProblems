#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;

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

int solution(string s) {
	int answer = 0;
	vector<int> pi = getPi(s);
	cout << s << "\n";
	for (const auto d : pi) { cout << d << " "; }cout << "\n";

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<string> str{ "aabbaccc","ababcdcdababcdcd","abcabcdede" ,"abcabcabcabcdededededede" ,"xababcdcdababcdcd" };
	//cin >> s;
	for (const auto d : str)
	{
		solution(d);
	}
	//cout << solution(s) << "\n";
	return 0;
}