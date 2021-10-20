#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans;
vector<int> a;
vector<int> b;

void Proc() 
{
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	for (int i = 0; i < N; i++) 
	{
		ans += (a[i] * b[i]);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	a = vector<int>(N, 0);
	b = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> b[i];
	}
	Proc();
	cout << ans << "\n";
	return 0;
}