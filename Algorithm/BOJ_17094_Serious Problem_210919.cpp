#include <iostream>

using namespace std;

int N, count2, countE;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		char c = ' '; cin >> c;
		if (c == '2') count2++;
		else countE++;
	}
	cout << ((count2 == countE) ? "yee\n" : ((count2 < countE) ? "e\n" : "2\n"));
	return 0;
}