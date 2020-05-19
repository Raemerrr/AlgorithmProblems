#include <iostream>
#include <map>

using namespace std;
map<int, bool> m;
int N, M;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int key = 0;
		cin >> key;
		m[key] = true;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int key = 0;
		cin >> key;
		if (m[key])
		{
			cout << "1 ";
		}
		else
		{
			cout << "0 ";
		}
	}
	cout << "\n";
	return 0;
}