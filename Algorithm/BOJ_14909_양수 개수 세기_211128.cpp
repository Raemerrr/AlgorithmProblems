#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int answer = 0;
	while (!cin.eof())
	{
		int num = 0; cin >> num;
		answer += ((0 < num) ? 1 : 0);
	}
	cout << answer << "\n";
	return 0;
}