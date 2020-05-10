#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> temp;
long long ans;

void Proc()
{
	for (int i = 0; i < v.size(); i++)
	{
		while (!temp.empty() && temp[temp.size() - 1] <= v[i])
		{
			temp.pop_back();
		}
		temp.emplace_back(v[i]);
		ans += temp.size() - 1;
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