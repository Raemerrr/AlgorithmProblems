#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i = 10, sum = 0, answer = 0;
	while (0 < i)
	{
		int in = 0, out = 0; cin >> out >> in;
		sum -= out;
		sum += in;
		answer = ((answer < sum) ? sum : answer);
		i--;
	}
	cout << answer << "\n";
	return 0;
}