#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		string str; cin >> str;
		int sum = 0;
		reverse(str.begin(), str.end());
		for (int i = 0; i < str.size(); i++)
		{
			//ÀÎµ¦½º Á¢±ÙÀ¸·Î È¦¼ö¹øÂ°°¡ Â¦¼ö¹øÂ°
			if (i % 2 != 0)
			{
				int j = str[i] - '0';
				j *= 2;
				if (j >= 10)
				{
					j = (j / 10) + (j % 10);
				}
				j %= 10;
				str[i] = j + '0';
			}
		}
		for (const char d : str) sum += d - '0';
		cout << ((sum % 10 == 0) ? "T" : "F") << "\n";
	}
	return 0;
}