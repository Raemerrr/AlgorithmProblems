#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		ans = 0;
		cin >> N >> K;
		vector<int> v(N, 0);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		if (N > 1)
		{
			//±¸Çö
			for (int i = 0; i < N - 1; i++)
			{
				int tempAns = 1;
				for (int j = i + 1; j < N; j++)
				{
					if (v[j] - v[i] <= K)
					{
						tempAns++;
					}
					else
					{
						break;
					}
				}
				ans = (ans > tempAns) ? ans : tempAns;
			}
			cout << "#" << t + 1 << " " << ans << "\n";
		}
		else
		{
			cout << "#" << t + 1 << " 1\n";
		}
	}
	return 0;
}