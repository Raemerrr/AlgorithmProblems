#include <iostream>

using namespace std;

long long N;

void binary(long long num) {
	if (num == 1)
		cout << num;
	else
	{
		binary(num / 2);
		cout << num % 2;
	}
}

int main() {
	cin >> N;
	binary(N);
	cout << "\n";
	return 0;
}