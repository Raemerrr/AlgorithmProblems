#include <iostream>
#include <map>

using namespace std;

map<int, int> m;
int N, v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		int num = 0; cin >> num;
		m[num]++;
	}
	cin >> v;
	cout << m[v] << "\n";
	return 0;
}