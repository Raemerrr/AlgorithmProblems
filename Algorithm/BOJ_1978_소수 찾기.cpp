#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<int> v;

bool check(const int num) 
{
	bool flag = false;
	if (num > 1)
	{
		int cnt = 0;
		for (int i = 2; i <= num; i++)
		{
			if (num % i == 0)
			{
				cnt++;
				if (cnt > 1)
				{
					break;
				}
			}
		}
		if (cnt == 1)
		{
			flag = true;
		}
	}
	return flag;
}

void Proc() 
{
	for (const auto d : v) 
	{ 
		if (check(d) )
		{ 
			ans++;
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	Proc();
	cout << ans << "\n";
	return 0;
}