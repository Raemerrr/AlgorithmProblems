#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v{ 0,0,0 };
int main()
{
	cin >> N;
	if (N % 10 > 0)
	{
		cout << "-1\n";
		return 0;
	}
	while (N >= 10)
	{
		if (N >= 300)
		{
			N -= 300;
			v[0]++;
		}
		else if (N >= 60)
		{
			N -= 60;
			v[1]++;
		}
		else if (N >= 10)
		{
			N -= 10;
			v[2]++;
		}
	}
	if (N > 0)
	{
		cout << "-1\n";
	}
	else
	{
		for (const auto& d : v) { cout << d << " "; }cout << "\n";
	}
	return 0;
}