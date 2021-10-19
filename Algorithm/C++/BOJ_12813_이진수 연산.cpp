#include <iostream>
#include <bitset>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	bitset<100000> bt1;
	bitset<100000> bt2;
	cin >> bt1 >> bt2;
	cout << (bt1 & bt2) << "\n";
	cout << (bt1 | bt2) << "\n";
	cout << (bt1 ^ bt2) << "\n";
	cout << (~bt1) << "\n";
	cout << (~bt2) << "\n";
	return 0;
}