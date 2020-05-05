/*
원본 문자열 += 원본 문자열 - 1
9
I W A N T M E A T I W A N T M E A
		E A T I W A N T M
원본 문자열 내 1회 존재

6
A A B A A B A A B A A
	B A A B A A
		  B A A B A A
//아래와 같은 상황을 대비해 원본 문자열 -1 만큼 추가한다.
I W A N T M E A T I W A N T M E A T
I W A N T M E A T I W A N T M E A T - (이러한 경우 2회 존재하는 것으로 판단 가능성 있음.)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//원본, 패턴
string str, p;
int N;

//유클리드 호제법
int GCD(int a, int b)
{
	if (a < b)
	{
		swap(a, b);
	}
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

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

int KMP(const string& s, const string& pattern)
{
	//문자열 속 등장 횟수
	int cnt = 0;
	vector<int> pi = getPi(pattern);
	for (int i = 0, j = 0; i < s.size(); i++)
	{
		while (j > 0 && s[i] != pattern[j])
		{
			j = pi[j - 1];
		}
		if (s[i] == pattern[j])
		{
			//패턴이 매칭되었다면
			if (j == pattern.size() - 1)
			{
				cnt++;
				j = pi[j];
			}
			else
			{
				++j;
			}
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	str = string(N, '0');
	p = string(N, '0');
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> p[i];
	}
	//키 포인트*
	str += str;
	// 마지막 문자 없애기.
	str.pop_back();
	int ans = KMP(str, p);
	int div = GCD(N, ans);
	//포함 문자 개수 / 최대 공약수  전체 문자 길이 / 최대 공약수
	cout << ans / div << "/" << N / div << "\n";
	return 0;
}