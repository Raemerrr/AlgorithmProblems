#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());
	unsigned long long s = 1;
	unsigned long long e = times.back() * n;
	while (s <= e)
	{
		unsigned long long mid = (s + e) / 2;
		unsigned long long sum = 0;
		for (const int d : times) {
			sum += mid / d;
		}
		if (n <= sum)
		{
			e = mid - 1;
		}
		else //if (sum < n)
		{
			s = mid + 1;
		}
	}
	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n = 6;
	//int n = 10;
	vector<int> times{ 7, 10 };
	//vector<int> times{ 1, 5 };
	cout << solution(n, times) << "\n";
	return 0;
}