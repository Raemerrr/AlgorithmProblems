#include <iostream>
#include <string>

using namespace std;

bool isPrime(const int num) {
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string str; cin >> str;
	int num = 0;
	for (const char d : str) {
		if (isupper(d))
		{
			num += (d - 'A' + 27);
		}
		else
		{
			num += ( d - 'a' + 1);
		}
	} 
	cout << (isPrime(num) ? "It is a prime word." : "It is not a prime word.") << "\n";
	return 0;
}