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
		//모든 경우의 접두어를 이용하기 위해. substr() 사용
		vector<int> pi = getPi(str.substr(i));
		for (const auto d : pi)
		{
			//부분 문자열의 가장 큰 값 구하기
			ans = (ans > d) ? ans : d;
		}
	}
	cout << ans << "\n";
	return 0;
}