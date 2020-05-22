#include <iostream>
#include <map>

using namespace std;
int N, M;
map<int, int> m;
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		m[num]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num = 0;
		cin >> num;
		cout << m[num] << " ";
	}
	cout << "\n";
	return 0;
}