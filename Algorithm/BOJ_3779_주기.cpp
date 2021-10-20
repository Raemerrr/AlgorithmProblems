#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
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

//유클리드 호제법
int GCD(int a, int b)
{
	if (a < b) { swap(a, b); }
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 1;
	while (true)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}
		cin >> str;
		vector<int> pi = getPi(str);
		cout << "Test case #" << test_case << "\n";
		for (int i = 0; i < pi.size(); i++)
		{
			if (pi[i] != 0)
			{
				int index = i + 1;
				int div = GCD(index, pi[i]);
				if (index == pi[i] + div)
				{
					cout << index << " " << index / div << "\n";
				}
			}
		}
		cout << "\n";
		test_case++;
	}
	return 0;
}