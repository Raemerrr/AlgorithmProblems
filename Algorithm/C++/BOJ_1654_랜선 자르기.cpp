#include <iostream>
#include <vector>
#include <algorithm>

#define UI unsigned int
#define ULL unsigned long long
using namespace std;

UI N, M, ans;
vector<UI> v;

ULL  Cutting(const UI mid)
{
	ULL cnt = 0;
	for (const auto& d : v)
	{
		if (d >= mid)
		{
			cnt += (d / mid);
		}
	}
	return cnt;
}

void Proc()
{
	UI left = 0;
	UI right = v[v.size() - 1];
	while (left <= right)
	{
		UI mid = 1;
		if ((right + left) != 1)
		{
			mid = (right + left) / 2;
		}
		ULL c = Cutting(mid);
		if (M <= c)
		{
			left = mid + 1;
			ans = (ans > mid) ? ans : mid;
		}
		// M > c
		else
		{
			right = mid - 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<UI>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	Proc();
	cout << ans << "\n";
	return 0;
}