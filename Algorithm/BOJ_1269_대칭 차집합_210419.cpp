#include <iostream>
#include <map>

using namespace std;

int N, M, answer;
map<int, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int num = 0; cin >> num;
		m[num]++;
	}
	for (int i = 0; i < M; i++)
	{
		int num = 0; cin >> num;
		m[num]++;
	}
	for (const pair<int,int>& d : m) {
		if (d.second != 2)
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}