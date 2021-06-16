#include <iostream>
#include <set>

using namespace std;

int N;
set<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		int num = 0; cin >> num; s.insert(num);
	}
	for (const auto d : s) cout << d << " ";
	return 0;
}