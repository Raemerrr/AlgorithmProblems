#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

unsigned int num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> num;
	string str = bitset<32>(num).to_string();
	reverse(str.begin(), str.end());
	while (!str.empty() && str.back() == '0') str.pop_back();
	cout << bitset<32>(str).to_ulong() << "\n";
	return 0;
}