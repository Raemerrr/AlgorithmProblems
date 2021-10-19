#include <iostream>
#include <bitset>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	bitset<7> bt = num;
	cout << bt.count() << "\n";
	return 0;
}