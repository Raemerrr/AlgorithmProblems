/*
입력:
4 10
1 4 5 7

정답:
2

출력:
3

4 6
2 5 7 8

*/
#include <iostream>
#include <vector>
#include <algorithm>
#define ULL unsigned long long

using namespace std;

ULL N, M, MAX;
vector<ULL> v;

ULL cutting(const ULL h)
{
	ULL n = 0;
	for (const auto& d : v)
	{
		if (h < d)
		{
			n += (d - h);
		}
	}
	return n;
}

ULL binarySearch()
{
	ULL left = 0;
	ULL right = v[v.size() - 1];
	ULL ans = 0;
	while (left <= right)
	{
		ULL mid = (right + left) / 2;
		ULL c = cutting(mid);
		if (M <= c)
		{
			ans = (ans > mid) ? ans : mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<ULL>(N, 0);
	for (int i = 0; i < N; i++) { cin >> v[i]; }
	sort(v.begin(), v.end());
	cout << binarySearch() << "\n";
	return 0;
}