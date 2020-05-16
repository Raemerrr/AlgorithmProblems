#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> nV;
vector<int> mV;

int binarySearch(const int n)
{
	int left = 0;
	int right = nV.size();
	int mid = right / 2;
	if (n < nV[mid])
	{
		right = mid;
		while (n < nV[right])
		{
			if (right > 1 && n < nV[right / 2]) { right /= 2; }
			else { break; }
		}
	}
	else
	{
		left = mid;
		while (n >= nV[left])
		{
			int diff = (right - left) / 2;
			if (left < nV.size() - 1 && n >= nV[left + (diff)]) { left += diff; }
			else { break; }
		}
	}
	for (int i = left; i < right; i++)
	{
		if (nV[i] == n)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	nV = vector<int>(N, 0);
	for (int i = 0; i < N; i++) { cin >> nV[i]; }
	sort(nV.begin(), nV.end());
	cin >> M;
	mV = vector<int>(M, 0);
	for (int i = 0; i < M; i++) { cin >> mV[i]; }
	for (const auto& d : mV) { cout << binarySearch(d) << "\n"; }
	return 0;
}