#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

const int three = 3;
const int five = 5;


/*
 * Complete the 'fizzBuzz' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

int GCD(int a, int b)
{
	if (a < b) { swap(a, b); }
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

void fizzBuzz(int n) {
	for (int i = 1; i <= n; i++)
	{
		if (i >= three)
		{
			if (i >= five && GCD(i, five) == five && GCD(i, three) == three)
			{
				cout << "FizzBuzz";
			}
			else if (GCD(i, three) == three)
			{
				cout << "Fizz";
			}
			else if (i >= five && GCD(i, five) == five)
			{
				cout << "Buzz";
			}
			else
			{
				cout << i;
			}
		}
		else
		{
			cout << i;
		}
		cout << "\n";
	}
}

int main()
{
	string n;
	cin >> n;
	fizzBuzz(stoi(n));
	return 0;
}

