#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long LL;
int T, N, M;
LL answer;
vector<int> A, B;
vector<LL> aSum, bSum;


void func(vector<int>& arr, vector<LL>& sum)
{
	for (int j = 0, size = arr.size(); j < size; j++)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (i == 0)
			{
				sum.push_back(arr[i]);
			}
			else
			{
				sum.push_back(arr[i] + sum.back());
			}
		}
		arr.erase(arr.begin());
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T >> N;
	A.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> M;
	B.assign(M, 0);
	for (int i = 0; i < M; i++) cin >> B[i];
	func(A, aSum), func(B, bSum);
	sort(aSum.begin(), aSum.end()), sort(bSum.begin(), bSum.end());
	set<LL> s(aSum.begin(), aSum.end());
	for (const LL d : s)
	{
		LL tempAns = (upper_bound(bSum.begin(), bSum.end(), T - d) - lower_bound(bSum.begin(), bSum.end(), T - d));
		tempAns *= (upper_bound(aSum.begin(), aSum.end(), d) - lower_bound(aSum.begin(), aSum.end(), d));
		answer += tempAns;
	}
	cout << answer << "\n";
	return 0;
}