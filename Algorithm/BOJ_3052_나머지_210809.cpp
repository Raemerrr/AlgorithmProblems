#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	set<int> s;
	for (int i = 0; i < 10; i++)
	{
		int num = 0; cin >> num;
		s.insert(num % 42);
	}
	cout << s.size() << "\n";
	return 0;
}