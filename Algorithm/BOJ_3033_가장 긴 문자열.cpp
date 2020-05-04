#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int BIG_PRIME = 1000003;
int len;
string str;

int MOD(const long long num)
{
	if (num >= 0) { return num % BIG_PRIME; }
	else { return ((-num / BIG_PRIME + 1)*BIG_PRIME + num) % BIG_PRIME; }
}

void Proc()
{
	int mid = 0, left_most = 0, right_most = len, power = 1, curH = 0;
	while (left_most + 1 < right_most)
	{
		bool found = false;
		power = 1; curH = 0;
		mid = (left_most + right_most) / 2;
		vector<vector<int>> hIDX = vector<vector<int>>(BIG_PRIME, vector<int>());
		for (int i = 0; i < len - mid + 1; i++)
		{
			if (i == 0)
			{
				for (int j = 0; j < mid; j++)
				{
					curH = MOD(curH + 1LL * str[mid - j - 1] * power);
					if (j < mid - 1)
					{
						power = MOD(power * 2);
					}
				}
			}
			else
			{
				curH = MOD(2 * (curH - 1LL * str[i - 1] * power) + str[mid + i - 1]);
			}
			if (hIDX[curH].empty())
			{
				hIDX[curH].emplace_back(i);
			}
			else
			{
				if (strncmp(&str[hIDX[curH][0]], &str[i], mid - 1) == 0)
				{
					found = true;
					break;
				}
			}
		}
		if (found) { left_most = mid; }
		else { right_most = mid; }
	}
	cout << left_most << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> len >> str;
	Proc();
	return 0;
}