#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T = 0; cin >> T;
	while (T--)
	{
		int k = 0; cin >> k;
		int answer = 1;
		for (int i = 1; i < k; i++) {
			answer = answer * 2 + 1;
		}
		cout << answer << "\n";
	}
	return 0;
}