/*
���� ���ڿ� += ���� ���ڿ� - 1
9
I W A N T M E A T I W A N T M E A
		E A T I W A N T M
���� ���ڿ� �� 1ȸ ����

6
A A B A A B A A B A A
	B A A B A A
		  B A A B A A
//�Ʒ��� ���� ��Ȳ�� ����� ���� ���ڿ� -1 ��ŭ �߰��Ѵ�.
I W A N T M E A T I W A N T M E A T
I W A N T M E A T I W A N T M E A T - (�̷��� ��� 2ȸ �����ϴ� ������ �Ǵ� ���ɼ� ����.)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//����, ����
string str, p;
int N;

//��Ŭ���� ȣ����
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
	//���ڿ� �� ���� Ƚ��
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
			//������ ��Ī�Ǿ��ٸ�
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
	//Ű ����Ʈ*
	str += str;
	// ������ ���� ���ֱ�.
	str.pop_back();
	int ans = KMP(str, p);
	int div = GCD(N, ans);
	//���� ���� ���� / �ִ� �����  ��ü ���� ���� / �ִ� �����
	cout << ans / div << "/" << N / div << "\n";
	return 0;
}