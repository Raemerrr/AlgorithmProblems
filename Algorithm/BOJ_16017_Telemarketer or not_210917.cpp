#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 4;
vector<int> v;

bool is8or9(const int num) {
	if (num == 8 || num == 9) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	v.assign(SIZE, 0);
	for (int i = 0; i < SIZE; i++) cin >> v[i];
	if (is8or9(v.front()) && is8or9(v.back()) && v[1] == v[2])
		cout << "ignore\n";
	else
		cout << "answer\n";
	return 0;
}