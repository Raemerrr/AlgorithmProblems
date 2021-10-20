#include <iostream>

using namespace std;
unsigned long long A, B, V;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> V;
	unsigned long long ans = (V - B - 1) / (A - B) + 1;
	cout << ans << "\n";
	return 0;
}